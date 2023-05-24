#include "shell.h"
/**
 * free_all - frees all malloc'd space 
 * @tkns: ptr to token array
 * @path: ptr to path var
 * @cmd: ptr to user input
 * @full_path: ptr to full path
 * @flag: flag marking fullpath malloc
 * Return: nothing
 */
void free_all(char **tkns, char *path, char *line, char *full_path, int flag)
{
	free(path);
	free(tkns);
	free(cmd);
	if (flag == 1)
		free (full_path);
}

/**
 * free_doubleptr - free double pointer
 * @array: double ptr to be freed
 * @len: double ptr length
 * Return: nothing
 */
void free_double_ptr(char **array, unsigned int len)
{
	unsigned int i = 0;

	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

