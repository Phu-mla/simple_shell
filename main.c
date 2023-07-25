#include "main.h"
/**
 *
 * main - Entry point 
 * Return: 0 (success)
 **/

int main(void)
{
	int child_state, builtin_state, flag;
	char **tkns;
	char *input, *path, *full_path;
	struct stat buff;

	while (1)
	{
		cue(STDIN_FILENO, buff);
		input = get_line(stdin);
		if (str_cmp(input, "\n", 1) == 0)
		{
			free(input);
			continue;
		}
		tkns = token_maker(input);
		if (tkns[0] == NULL)
			continue;
		builtin_state = exec_builtin(tkns);
		if (builtin_state == 0 || builtin_state == -1)
		{
			free(tkns);
			free(input);
		}
		if (builtin_state == 0)
			continue;
		if (builtin_state == -1)
			_exit(EXIT_SUCCESS);

		flag = 0;
		path = get_env("PATH");
		full_path = search_(tkns[0], full_path, path);
		if (full_path == NULL)
			full_path = tkns[0];
		else
			flag = 1;
		child_state = child(full_path, tkns);
		if (child_state == -1)
			print_error(3);
		free_all(tkns, path, input, full_path, flag);
	}
	return (0);
}
		
		
