#include "shell.h"

/**
 * createChildProcess - forks a process and create a new child process
 *
 * Return: The pid of the created process
 */

pid_t createChildProcess(void)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	return (pid);
}
