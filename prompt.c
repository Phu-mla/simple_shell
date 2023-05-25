#include "shell.h"
/**
 * _prompt - Displays a prompt and waits for a user to type a command.
 *
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
		if (feof(stdin))
		{
			free(lineptr);
			lineptr = NULL;
			write(STDIN_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("getline");
			exit(EXIT_FAILURE);
		}
	}
	else if (chars_read == 0)
	{
		free(lineptr);
		lineptr = NULL;
	}
	else
	{
		/* Replace trailing newline character with a NULL byte */
		lineptr[strcspn(lineptr, "\n")] = '\0';
	}

	return (lineptr);
}
