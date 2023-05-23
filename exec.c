#include "shell.h"
#define MAX_ARGS 50

/**
 * runcmd - Handles and Executes a command 
 * @cmd: command to be executed
 *
 * Return : nothing
 */
void runcmd(char *cmd)
{
	char *args[] = {cmd, NULL};
	pid_t pid - createChildProcess();

	args[0] = cmd;
	args[1] = NULL;

	if (pid == 0)
	{
		execve(cmd, args, NULL);
	
	/* If the execution reaches this point,
	 * it means the command couldn't be executed
	 */
	/* perror(args[0]); */
	perror("./shell");
	}
	else waitForChild();

}
