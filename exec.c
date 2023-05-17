#include "main.h"

/**
 * runcmd - Handles and Executes a command 
 */
void runcmd(char *cmd)
{
	char *args[] = {cmd, NULL};
	execve(cmd, args, NULL);
	
	/* If the execution reaches this point,
	 * it means the command couldn't be executed
	 */
	/* perror(args[0]); */
	perror("./shell");
}
