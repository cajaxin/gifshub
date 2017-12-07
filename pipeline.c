#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>

int pipeline(FILE *fpin, FILE *fpout, const char *cmd1, cost char *cmd2, ...) {
	/* variáveis iniciais */
	int i;
	int ncmds = 2; /* há pelo menos 2 comandos, obrigatoriamente (*cmd1 e *cmd2) */
	char **command = NULL;
	va_list cmds; /* tipo maluco pra usar o que vier nas reticências */
	/* contar numero total de argumentos */
	va_start(cmds, cmd2);
	while (va_arg(cmds, char*) != NULL) {
		ncmds++;
	}
	va_end(cmds);
	/* gerar vetor com todos os argumentos e ficar livre de uma vez desse va_arg dos infernos */
	command = malloc (ncmds * sizeof(char*));
	command[0] = cmd1;
	command[1] = cmd2;
	va_start(cmds, cmd2);
	for(i = 2; i < ncmds; i++) {
		command[i] = va_arg(cmds, char*);
	}
	va_end(cmds);
	/* agora a gente separa os homens dos meninos, digo, agora a gente começa a execução dos comandos */
	

	return 0;
}