#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#define MAX_ARGS 100

int run (char* command, int *result) {
//command: "program arg1 arg2… argN”
	pid_t pid;
	int res;
	pid = fork();
	printf("I am the pid: %d\n", pid);
	if (pid == 0) {
		*result = system(command);
		printf("%s\n", result);
	//	printf("%d\n", getpid());
		return getpid();
	} else if (pid < 0) {
		wait(&command); //verificar  tentar usar pipe
		printf("%s\n", "pid < 0");
		return 0; //finish process
	}
	if (result != NULL) {
		printf("%s\n", "returning pid");
		return pid;
	} else 
		return -1;
}