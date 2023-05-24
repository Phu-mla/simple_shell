#include "shell.h"
/**
 * get_env - gets environment variable
 * @name: environment variable to get
 * Return : ptr to variable, NULL if no match is found
 */
char *get_env(const char *name)
{
	char *var, *value, *path;
	char **cpy_environ;
	int cmp;
	unsigned int len, len_path, len_environ, i;

	len_environ = 0;

	while (environ[len_environ] != NULL)
		++len_environ;

	cpy_environ = NULL;
	cpy_environ = copy_env(cpy_environ, len_environ);

	len = strlen((char*)name);
	i = 0;

	while (cpy_environ[i] != NULL)
	{
		var = cpy_environ[i];
		cmp = strcmp((char*)name, var, len);
		if (cmp == 1)
		{
			value = strtok(var, "=");
			value = strtok(NULL, "\n ");
			if (value == '\0')
			{
				perror("PATH ERROR");
				exit(EXIT_FAILURE);
			}
			len_path = strlen(value);
			path = malloc(sizeof(char) * len_path + 1);

			if (path == NULL)
			{
				errors(3);
				return (NULL);
			}
			path = strcpy(path, value);
			free_doubleptr(cpy_environ, len_environ);
			return (path);
		}
		i++;
	}
	return (NULL);
}

