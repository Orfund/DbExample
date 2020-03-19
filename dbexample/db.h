//
//  db.h
//  dbexample
//
//  Created by Дмитрий Маслюков on 18.03.2020.
//  Copyright © 2020 Дмитрий Маслюков. All rights reserved.
//

#ifndef db_h
#define db_h

#include "filework.h"
#include <stdlib.h>
extern struct ArrayRecords _array;

struct choice {
    char * bitset;
};

struct choice Select(const char * name, int grMin, int grMax);
void printChoice(struct choice);

#endif /* db_h */
