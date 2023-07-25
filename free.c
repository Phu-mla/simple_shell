#include "main.h"
/**
 * free_all - free all malloc'd soace after main
 *@tkns: ptr to tokens
 *@path: ptr to path
 *@line: ptr to input
 *@full_path: ptr to the full path
 *@flag: marker for the malloc of full_path
 */
void free_all(char **tkns, char *path, char *line, char *fpath, int flag)
{
	free(path);
	free(line);
	free(tkns);
	if (flag == 1)
	  free(fpath);
}

/**
 * 
 * free_double - free double ptr
 * @array: ptr to free
 * @len: double ptr length
 */

void free_double(char **array, unsigned int len)
{
	unsigned int x = 0;
	while (x < len)
	{
		free(array[x]);
		x++;
	}
	free(array);
}

	
