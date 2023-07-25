#include "main.h"
/**
 *get_env - get environment
 *@env_var: environment variable
 *Return: ptr to env varniable
 */

char *get_env(const char *env_var)
{
	unsigned int path_len, len_env, len, x;
	char *var, *val, *path;
	char **cpy_environ;
	int comp;

	len_env = 0;
	while(environ[len_env] != NULL)
		len_env++;
	cpy_environ = NULL;
	cpy_environ = cpy_env(cpy_environ, len_env);

	len = str_len((char *)env_var);

	x = 0;
	
	while (cpy_environ[x] != NULL)
	{
		var = cpy_environ[x];
		comp = strn_cmp((char *)env_var, var, len);
		if (comp == 1)
		{
			val = strtok(var, "=");
			val = strtok(NULL, "\n ");
			if (val == NULL)
			{
			print_error(4);
			exit(EXIT_FAILURE);
			}
			path_len = str_len(val);
			path = malloc(sizeof(char) * path_len + 1);
			if (path == NULL)
			{
				print_error(1);
				return (NULL);
			}
			path = str_cpy(path, val);
			free_double(cpy_environ, len_env);
			return (path);
	}	
		x++;
	}
	return (NULL);
}

/**
*cpy_env - copy environ variable
*@cpy_environ: ptr to copy of envnironment variable
*@len_env: length of env variable
*Return: double ptr to copy env
*/

char **cpy_env(char **cpy_environ, unsigned int len_env)
{
	unsigned int len_var, x;
	char *var;

	cpy_environ = malloc(sizeof(char**) * (len_env));
	if (cpy_environ == NULL)
	{
		print_error(1);
		return (NULL);
	}

	x = 0;
	while (x < len_env)
	{
		var = environ[x];
		len_var = str_len(var);

		cpy_environ[x] = malloc(sizeof(char) * len_var + 1);
		if (cpy_environ[x] == NULL)
		{
			print_error(1);
			return (NULL);
	  	}		
		str_cpy(cpy_environ[x], environ[x]);
		x++;
	}

	return (cpy_environ);
}
