#include "main.h"

/**
* child - child process
* @full_path: executable path
* @tkns: input that has been tokenised
* Return: 0 - success
*/

int child(char *fpath, char **tkns)
{
 	pid_t child_pid;
	int state, execve_state;
	char **envp = environ;

	child_pid = fork();
	if (child_pid == -1)
	{
		print_error(2);
		exit(EXIT_FAILURE);
	}
	if (child_pid == 0)
	{
		execve_state = execve(fpath, tkns, envp);
		if (execve_state == -1)
			return (-1);
	}
	else
		wait(&state);

	return (0);
}

	
	
