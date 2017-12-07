#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	int fd[2];
	pid_t childpit;
	
	pipe(fd);

	if((childpit = fork() == -1)) {
		perror("fork");
		exit(1);
	}

	if(childpit == 0) {
		/* Child process closes up input side of pipe */
		close(fd[0]);
		/* Send "string" through the output side of pipe */
		
	}
	else {
		/* Parent process closes up output side of pipe */
		close(fd[1]);
		/* Read in a string from the pipe */
		
	}

	return 0;
}