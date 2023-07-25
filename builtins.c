#include "main.h"
#include <unistd.h>
/**
 *exit_shell - exits the shell
 */

	int exit_shell(void)
	{

		return (-1);
	}

/**
 *
 *print_env - print current environment
 */

	int print_env(void)
	{
		unsigned int x = 0;
	
		while(environ[x] != NULL)
		{	
			write(STDOUT_FILENO, environ[x], str_len(environ[x]));
			write(STDOUT_FILENO, "\n", 1);
			x++;
		}
		return (0);
}
