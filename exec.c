#include "shell.h"

/**
 * runcmd - Handles and Executes a command
 * @cmd: command to be executed
 *
 * Return : nothing
 */
void runcmd(char *cmd)
{
	char *path, **args = tokenizeCommand(cmd);
	pid_t pid;

	if (args == NULL)
	{
		fprintf(stderr, "Failed to tokenize the command\n");
		exit(EXIT_FAILURE);
	}

	path = searchProgram(args[0]);
	if (path != NULL)
	{
		pid = createChildProcess();
		if (pid == 0)
		{
			execve(path, args, environ);

			/*
			 * If the execution reaches this point,
			 * it means the command couldn't be executed
			 */
			/* perror(args[0]); */
			perror("./shell");
		}
		else
			waitForChild();
	}
	else
		printf("Command not found: %s\n", args[0]);
}
