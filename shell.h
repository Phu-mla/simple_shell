#ifndef SHELL_H
#define SHELL_H

/******** C Standard Libraries ********/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/******** MACROS *********/
#define MAX_ARGS 50

/******** Global Variables ********/
extern char **environ;

/******** Function Prototypes ********/
void run_shell(void);
char *_prompt();
void runcmd(char *cmd);
pid_t createChildProcess(void);
void waitForChild(void);
char **tokenizeCommand(char *command);
char *searchProgram(const char *program);

#endif /* SHELL_H */
