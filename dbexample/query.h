//
//  query.h
//  dbexample
//
//  Created by Дмитрий Маслюков on 18.03.2020.
//  Copyright © 2020 Дмитрий Маслюков. All rights reserved.
//

#ifndef query_h
#define query_h

#include "db.h"
// select name Sasha

struct SearchData {
    char name [20];
    int grMin;
    int grMax;
};

struct SearchData parse_query(const char * s_query);

#endif /* query_h */
