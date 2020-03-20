//
//  server.h
//  dbexample
//
//  Created by Дмитрий Маслюков on 20.03.2020.
//  Copyright © 2020 Дмитрий Маслюков. All rights reserved.
//

#ifndef server_h
#define server_h

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>  /* Needed for getaddrinfo() and freeaddrinfo() */
#include <unistd.h> /* Needed for close() */

extern int serv_fd;

typedef struct {
    char query[2048];
    int client_fd;
    FILE * fclient;
} conn_t;


void init_server(int portno);
conn_t get_client(void);
void process (conn_t connection);

/*
 init_server(8099);
 while(1){
    conn_t connection = get_client();
    process(connection);
 }
 */

#endif /* server_h */
