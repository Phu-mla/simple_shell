#include "main.h"

/**
 * print_error - prints errors on a case basis
 * @err: error associated with error statement
 *
 */

void print_error(int err)
{
	switch (err)
	{
	case 1: 
	/*malloc error*/
		write(STDERR_FILENO, ERR_MALLOC, str_len(ERR_MALLOC));
		break;

	case 2:
	/*fork error*/
		write(STDERR_FILENO, ERR_FORK, str_len(ERR_MALLOC));
		perror("Error");
		break;

	case 3:
	/*execve error*/
		perror("Error");
		break;

	case 4:
	/* empty path error */
		write(STDERR_FILENO, ERR_PATH, str_len(ERR_PATH));
		break;

	default:
		return;
	}
}
	
