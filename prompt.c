#include "shell.h"
/**
 * Displays a prompt and waits for a user to type a command.
 * Return: A Pointer to the prompt string
 */
char *_prompt()
{
	char *lineptr = NULL;
	size_t line_len = 0;
	ssize_t chars_read;

	printf("<^_^> ");
	fflush(stdout);
	chars_read = getline(&lineptr, &line_len, stdin);

	if (chars_read == -1)
	{
		printf("\n");
		free(lineptr);
		return (NULL);
	}

	/* Replace trailing newline character with a NULL byte */
	lineptr[strcspn(lineptr, "\n")] = '\0';
	
	return (lineptr);
}
