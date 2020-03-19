//
//  query.c
//  dbexample
//
//  Created by Дмитрий Маслюков on 18.03.2020.
//  Copyright © 2020 Дмитрий Маслюков. All rights reserved.
//

#include "query.h"
#include <string.h>
// [name <name> ][grmin <grmin>] [grmax <grmax>]

int read_block(struct SearchData * sdata, const char * reader){
    char fieldname [10];
    char val [100];
    if( sscanf(reader, "%s%s", fieldname, val) <=0 ){
        return 0;
    }
    if( strcmp(fieldname, "name") == 0 ){
        strcpy(sdata->name, val);
    }
    if( strcmp(fieldname, "grmin") == 0 ){
        sdata->grMin = atoi(val);
    }
    if( strcmp(fieldname, "grmax") == 0 ){
        sdata->grMax = atoi(val);
    }
    return (int)strlen(fieldname) + (int)strlen(val) + 2;
}


struct SearchData parse_query(const char * s_query){
    struct SearchData sdata = {"", -1, 10000};
    const char * reader = s_query;
    while(*reader != '\n' && *reader != 0){
        reader += read_block(&sdata, reader);
    }
    return sdata;
}
