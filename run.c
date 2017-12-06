#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/* #define MAX_ARGS 100 */

int run (char* command, int *result) {
/* command: "program arg1 arg2… argN” */
	pid_t pid;
/*	int res; -- tá inútil  */
	pid = fork();
	
	if (pid == 0) {
		*result = system(command);
		printf("%d\n", getpid());
		return getpid();
	} else if (pid < 0) 
		return 0; /* finish process */

	if (result != NULL) {
		return pid;
	} else 
		return -1;
}