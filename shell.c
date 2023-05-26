#include "shell.h"

/**
 * run_shell - Run the shell
 */
void run_shell(void)
{
	char *command;
	size_t bufsize;

	if (isatty(STDIN_FILENO))
	{
		while ((command = _prompt()) != NULL)
		{
			runcmd(command);
			free(command);
		}
	}
	else
	{
		bufsize = 0;
		while (getline(&command, &bufsize, stdin) != -1)
		{
			command[strcspn(command, "\n")] = '\0';
			runcmd(command);
		}

		free(command);
	}
}
