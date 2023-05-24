#include "shell.h"

/**
 * waitForChild - waits for child process to terminate
 */
void waitForChild(void)
{
	wait(NULL);
}
