#include "shell.h"

/**
 * tokenizeCommand - Tokenize a command string into arguments
 * @command: The command string to tokenize
 *
 * Return: An array of strings representing the arguments,
 * terminated by a NULL pointer
 */
char **tokenizeCommand(char *command)
{
	char **args = malloc(MAX_ARGS * sizeof(char *));
	char *token = strtok(command, " ");
	int argCount = 0;

	if (args == NULL)
	{
		fprintf(stderr, "Failed to allocate Memory.\n");
		return (NULL);
	}

	while (token != NULL && argCount < MAX_ARGS - 1)
	{
		args[argCount] = token;
		argCount++;
		token = strtok(NULL, " ");
	}

	args[argCount] = NULL;

	return (args);
}
