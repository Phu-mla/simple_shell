#include "main.h"
/**
 *exec_builtin - runs builtins
 *@tkns: args
 *Return: tkns
 */

int exec_builtin(char **tkns)
{

	int state;
	unsigned int len, num, x;

	built_s builtin[] = {
		{"exit", exit_shell},
		{"env", print_env},
		{NULL, NULL}
	};

	if (tkns[0] == NULL)
		return (1);

	len = str_len(tkns[0]);

	num = num_builtins(builtin);

	for (x = 0; x < num; x++)
	{
		if(str_cmp(tkns[0], builtin[x].name, len) == 0)
		{
			state = (builtin[x].p)();
			return (state);
		}
	}
		return(1);
}

/**
 *num_builtins - check number of builtins
 *@builtin: the builtmin to be counted
 *Return: number of builtins
 */

int num_builtins(built_s builtin[])
{
	unsigned int x	= 0;

	while (builtin[x].name != NULL)
		x++;

	return (x);
}
