//
//  main.c
//  dbexample
//
//  Created by Дмитрий Маслюков on 18.03.2020.
//  Copyright © 2020 Дмитрий Маслюков. All rights reserved.
//

#include <stdio.h>
#include "filework.h"
#include "db.h"
#include "query.h"
int main(int argc, const char * argv[]) {
    _array = readRecords();
    char rdbuf [1000];
    fgets(rdbuf, 999, stdin);
    struct SearchData sdata = parse_query(rdbuf);
    struct choice c = Select(sdata.name, sdata.grMin, sdata.grMax);
    printChoice(c);
    return 0;
}
