#include "main.h"

/**
 * token_maker - tokenizes input string
 * @str: input to be tokenized
 * Return: ptr to tokenized array
**/

char **token_maker(char *str)
{
	unsigned int x;
	char *tkn;
	char **tkns;
	

	tkns = malloc(sizeof(char) * BUFFER);
	if (tkns == NULL)
	{
		print_error(1);

		exit(EXIT_FAILURE);
	}

	tkn = strtok(str, "\n\t\r ");

	x = 0;
	while (tkn != NULL)
	{
		tkns[x] = tkn;
		tkn = strtok(NULL, "\n\t\r ");
		x++;
	}

	tkns[x] = NULL;

	return (tkns);
}
