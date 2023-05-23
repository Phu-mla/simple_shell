#include "shell.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * child - function for child process
 * @fullpath: full path of executable
 * @tokens: tokenized user input
 * Return: 0 on success, -1 on failure
 */
int child(char *path, char **tokens)
{
    pid_t child;
    int status;
    char **envp = environ;

    child = fork();
    if (child == -1)
    {
        perror("Fork Error");
        exit(EXIT_FAILURE);
    }

    if (child == 0)
    {
        
        if (execve(path, tokens, environ) == -1)
        {
            perror("execve Error");
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        
        if (wait(&status) == -1)
        {
            perror("Wait Error");
            exit(EXIT_FAILURE);
        }
    }

    return 0;
}

