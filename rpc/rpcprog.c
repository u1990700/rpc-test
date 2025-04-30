#include <stdio.h>
#include <rpc/rpc.h>
#include "rpcprog.h"

/* 
   Simple "hello world" program that demonstrates an rpc call.
*/

main (int argc, char *argv[]) {

	CLIENT *cl;
	char **p;
	
	if (argc != 2) {
		printf("Usage: client hostname\n");
		exit(1);
	}

	cl = clnt_create(argv[1], HELLO_WOLRD_PROG, HELLO_WORLD_VERS, "tcp");
	if (cl == NULL) {
		clnt_pcreateerror(argv[1]);
		exit(1);
	}

	printf("Getting ready to call function to server\n");
	p = hw_1(NULL, cl);

	printf("Back from server\n");
	if (p == NULL) {
		clnt_perror(cl,argv[1]);
		exit(1);
	}

	printf("Returned date = %s\n", *p);

	return 0;
}
