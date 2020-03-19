//
//  filework.c
//  dbexample
//
//  Created by Дмитрий Маслюков on 18.03.2020.
//  Copyright © 2020 Дмитрий Маслюков. All rights reserved.
//

#include "filework.h"

void add(struct ArrayRecords * arr, struct record r){
    if(arr->rec_cap <= ++arr->rec_count){
        arr->rec_cap *= 2;
        arr->records = (struct record*)realloc(arr->records, sizeof(struct record)*arr->rec_cap);
    }
    arr->records[arr->rec_count - 1] = r;
}

struct ArrayRecords init_array(void){
    struct ArrayRecords arr;
    arr.rec_cap = 15;
    arr.rec_count = 0;
    arr.records = (struct record*)malloc(sizeof(struct record)*15);
    return arr;
}

struct ArrayRecords readRecords(void){
    FILE * fin = fopen("data.txt", "r");
    struct ArrayRecords array = init_array();
    char rdbuf [1000];
    while(fgets(rdbuf, 999, fin)){
        struct record r;
        sscanf(rdbuf, "%s%d", r.name, &r.groupNo);
        add(&array, r);
    }
    fclose(fin);
    return array;
}

void printRecords(struct ArrayRecords arr){
    for(int i = 0; i < arr.rec_count; i++){
        printf("name:%s group:%d\n",  arr.records[i].name, arr.records[i].groupNo);
    }
}
