#include "shell.h"

/**
 * run_shell - Run the shell
 */
void run_shell(void)
{
	char *command;

	while (1)
	{
		command = _prompt();

		runcmd(command);
	}
}
