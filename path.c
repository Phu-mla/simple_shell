#include "shell.h"

/**
 * createPath - Creates a program path by concatenating
 * directory and program name
 * @dir: The directory path
 * @program: The program name
 *
 * Return: The dynamically allocated program path
 */
char *createPath(const char *dir, const char *program)
{
	size_t dirlen = strlen(dir);
	size_t programlen = strlen(program);
	size_t pathlen = dirlen + programlen + 2;
	/* +2 for the '/' and '\0' characters */
	char *path = malloc(pathlen * sizeof(char));

	if (path == NULL)
	{
		fprintf(stderr, "Memory allocation for program path failed.\n");
		return (NULL);
	}

	snprintf(path, pathlen, "%s/%s", dir, program);
	return (path);
}

/**
 * searchProgram - Searches for programs in the PATH env variable.
 * @program: Name of the program to be searched
 *
 * Return: The full program path if found,
 * NULL if not found.
 */
char *searchProgram(const char *program)
{
	char *path, *pathEnv, *token;
	char *programPath = malloc(MAX_ARGS);

	if (access(program, X_OK) == 0)
	{
		/* The program exists and is executable */
		return (strdup(program));
	}

	pathEnv = getenv("PATH");
	if (pathEnv == NULL)
	{
		fprintf(stderr, "PATH environment variable not found");
		exit(EXIT_FAILURE);
	}

	path = strdup(pathEnv);
	token = strtok(path, ":");

	while (token != NULL)
	{
		programPath = createPath(token, program);

		if (access(programPath, X_OK) == 0)
		{
			/* program found in current path */
			free(path);
			return (programPath);
		}
		free(programPath);
		token = strtok(NULL, ":");
	}
	free(path);
	return (NULL);
}
