//
//  db.c
//  dbexample
//
//  Created by Дмитрий Маслюков on 18.03.2020.
//  Copyright © 2020 Дмитрий Маслюков. All rights reserved.
//

#include "db.h"
#include <string.h>
struct ArrayRecords _array;
struct choice Select(const char * name, int grMin, int grMax){
    struct choice choice;
    choice.bitset = (char*)malloc(_array.rec_count / 8 + 1);
    bzero(choice.bitset, _array.rec_count / 8 + 1);
    for(int i = 0; i < _array.rec_count; i++){
        char is_valid = 0;
        is_valid = strstr(_array.records[i].name, name) != 0 && (_array.records[i].groupNo >= grMin) && (_array.records[i].groupNo <= grMax);
        choice.bitset[ i / 8 ] |= is_valid << (i%8);
    }
    return choice;
}
void printChoice(struct choice c){
    for(int i = 0; i < _array.rec_count; i++){
        char is_valid = c.bitset[i/8] & (1 << (i%8));
        if(is_valid){
            printf("name:%s group:%d\n",  _array.records[i].name, _array.records[i].groupNo);
        }
    }
}
