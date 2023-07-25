
#include "main.h"

/**
* cue - checks if in interactive mode then prints the prompt
* @fd: file stream
* @buff: buffer
**/

void cue(int fd, struct stat buff)
{
	fstat(fd, &buff);
	if (S_ISCHR(buff.st_mode))
	_puts(PROMPT);
}

/**
* _puts - prints string
* @str: string to be printed
*/

void _puts(char *str)
{
	 unsigned int len;
	 len = str_len(str);
	
	 write(STDOUT_FILENO, str, len);
}
