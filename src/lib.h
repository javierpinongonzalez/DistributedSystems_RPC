#ifndef LIB_H
#define LIB_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>

typedef struct{
	char host_addr[12];
	char host_port[6];
} Host;

typedef struct{
	long msgNumber;
	char nickname[50];	
} User;


void close_correct(void);
void close_error(void);
void print_help(void);

int shellParser(char *,User, Host);
void getMessages(void);

void rsi_handler(int);

#endif