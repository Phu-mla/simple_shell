#include "shell.h"

/**
 * runcmd - Handles and Executes a command
 * @cmd: Command to be executed
 *
 * Return: nothing
 */
void runcmd(char *cmd)
{
	char *Path, **args = tokenizeCommand(cmd);
	pid_t pid;

	if (args == NULL)
	{
		fprintf(stderr, "Failed to tokenize the command\n");
		return;
	}

	Path = searchProgram(args[0]);
	if (programPath == NULL)
	{
		fprintf(stderr, "Command not found: %s\n", args[0]);
		free(args);
		return;
	}
	pid = createChildProcess();

	if (pid == 0)
	{
		execve(cmd, args, environ);

		/**
		 * If the execution reaches this point,
		 * it means the command couldn't be executed
		 */
		/* perror(args[0]); */

		perror("./shell");
	}
	else
		waitForChild();

}
