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
#include "server.h"
int main(int argc, const char * argv[]) {
    _array = readRecords();
    init_server(7009);
    while(1)process(get_client());
    return 0;
}
