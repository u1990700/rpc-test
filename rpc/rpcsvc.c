#include <rpc/rpc.h>
#include <stdio.h>
#include <time.h>
#include "rpcprog.h"

/* 
   Hello world RPC server -- it just returns the string.
*/

char **hw_1_svc(void *a, struct svc_req *req) {
	static char msg[256];
	static char *p;

	printf("getting ready to return value\n");
	time_t current_time;
        struct tm * time_info;
        char timeString[20];  // space for "HH:MM:SS\0"

        time(&current_time);
        time_info = localtime(&current_time);

        strftime(msg, sizeof(timeString), "%d-%m-%Y %H:%M:%S", time_info);
        p = msg;
	printf("Returning...\n");

	return(&p);
}
