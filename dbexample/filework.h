//
//  filework.h
//  dbexample
//
//  Created by Дмитрий Маслюков on 18.03.2020.
//  Copyright © 2020 Дмитрий Маслюков. All rights reserved.
//

#ifndef filework_h
#define filework_h

#include <stdio.h>
#include <stdlib.h>

struct record {
    char name [20];
    int groupNo;
};

struct ArrayRecords{
    struct record * records;
    int rec_count;
    int rec_cap;
};

void add(struct ArrayRecords * arr, struct record);
struct ArrayRecords init_array(void);
struct ArrayRecords readRecords(void);
void printRecords(struct ArrayRecords);

#endif /* filework_h */
