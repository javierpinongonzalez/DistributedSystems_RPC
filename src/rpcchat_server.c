/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */
#include <time.h>
#include "rpcchat.h"


typedef struct{ 
	char operator[20];
	char mensaje[100];
	long timestamp;
} MensajeDisco;



void *
writechat_1_svc(message *argp, struct svc_req *rqstp)
{
	static char * result;

	MensajeDisco *msgHDD = malloc(1 * sizeof(MensajeDisco));
	bzero(msgHDD->operator,20);
	bzero(msgHDD->mensaje,100);
	
	
	strcpy(msgHDD->operator,argp->operator);
	strcpy(msgHDD->mensaje,argp->message);
	msgHDD->timestamp = (long)time(NULL);
	printf("Escribiendo... [%s: %s]\n",msgHDD->operator,msgHDD->mensaje);
	
	FILE *file = fopen("messages.db","ab+");
	if ( file != NULL ) {
		fwrite(msgHDD,sizeof(MensajeDisco),1,file);
		fclose(file);
	}

	
	free(msgHDD);
	return (void *) &result;

}
historic *
getchat_1_svc(long *argp, struct svc_req *rqstp)
{
	static historic  result;
	int firstMessage = 10;
	int numMessages = 0;
	
		
	message *msglist = (message *)malloc(sizeof(message));	
	MensajeDisco *msgHDD = malloc(1 * sizeof(MensajeDisco));
	bzero(msgHDD->operator,20);
	bzero(msgHDD->mensaje,100);
	
	
	FILE *file = fopen("messages.db","rb");
	if ( file != NULL ) {
		while ( fread(msgHDD, sizeof(MensajeDisco),1,file) == 1 ) {
			if ( msgHDD->timestamp > *argp ) {  		

				if ( firstMessage == -10 ) {
					msglist = (message *) realloc(msglist, (numMessages+1) * sizeof(message));
				}

				msglist[numMessages].operator = (char *) malloc( sizeof(char) *20 );
				msglist[numMessages].message = (char *) malloc( sizeof(char) *100 );
				
				strcpy(msglist[numMessages].operator,msgHDD->operator);
				strcpy(msglist[numMessages].message,msgHDD->mensaje);
				msglist[numMessages].timestamp = msgHDD->timestamp;
				
				firstMessage = -10;
				numMessages++;
			}
		}
		fclose(file);
	} 
	
	result.list.list_val = msglist;
	result.list.list_len = numMessages;

	return &result;
}