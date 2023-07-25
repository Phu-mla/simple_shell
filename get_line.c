#include "main.h"

/**
 *get_line - puts user input in buffer line
 *@fp: buffer
 *Return: user input
 */

char *get_line(FILE *fp)
{
	size_t length;
	char *input;
	ssize_t read;

	length = 0;
	input = NULL;
	read = getline(&input, &length, fp);

	if (read == -1)
	{
		free(input);
		exit(EXIT_SUCCESS);
	}

	return (input);
}

