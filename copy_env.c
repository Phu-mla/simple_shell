#include "shell.h"
/**
 * copy_env - copies environment variable
 * @cpy_environ: ptr to copy of environment variable
 * @len_environ: length of environment var
 * Return: double ptr to copy of env variable
 */
char **copy_env(char **cpy_environ, unsigned int len_environ)
{
	char *var;
	unsigned int len_var, i;
	
	cpy_environ = malloc(sizeof(char **) * len_environ);
	if (cpy_environ == NULL)
	{
		perror("malloc failure");
		return (NULL);
	}
	i = 0;

	while (i < len_environ)
	{
		var = environ[i];
		len_var = strlen(var);

		cpy_environ[i] = malloc(sizeof(char) * len_var + 1);
		if (cpy_environ[i] == NULL)
		{
			perror("malloc failed");
			return (NULL)
		}
		strcpy(cpy_environ[i], environ[i]);
		i++;
	}
	return (cpy_environ);
}
