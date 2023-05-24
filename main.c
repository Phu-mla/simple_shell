#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void) {
    char* cmd = NULL;
    size_t bufsize = 0;
    char* tokens[10];
    char* path;
    char* full_path;
    int flag, builtin_status, child_status;
    struct stat buf;

    while (1) {
        prompt(STDIN_FILENO, buf);
        ssize_t read = getline(&cmd, &bufsize, stdin);
        if (read == -1 || line[0] == '\n') {
            continue;
        }
        line[strcspn(line, "\n")] = '\0';

        char* token = strtok(line, " ");
        int tokenIndex = 0;
        while (token != NULL && tokenIndex < 10) {
            tokens[tokenIndex] = token;
            token = strtok(NULL, " ");
            tokenIndex++;
        }
        tokens[tokenIndex] = NULL;

        if (tokens[0] == NULL) {
            continue;
        }

        builtin_status = -1;
        if (strcmp(tokens[0], "cd") == 0) {
            if (tokenIndex >= 2) {
                if (chdir(tokens[1]) != -1) {
                    builtin_status = 0;
                }
            }
        } else if (strcmp(tokens[0], "exit") == 0) {
            break;
        }

        if (builtin_status == -1) {
            flag = 0;
            path = getenv("PATH");
            fullpath = NULL;

            if (path != NULL) {
                char* dir = strtok(path, ":");
                while (dir != NULL) {
                    char* temp = malloc(strlen(dir) + strlen(tokens[0]) + 2);
                    sprintf(temp, "%s/%s", dir, tokens[0]);
                    if (access(temp, X_OK) == 0) {
                        fullpath = temp;
                        flag = 1;
                        break;
                    } else {
                        free(temp);
                    }
                    dir = strtok(NULL, ":");
                }
            }

            if (fullpath == NULL) {
                fullpath = tokens[0];
            }

            pid_t pid = fork();

            if (pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (pid == 0) {
                if (execvp(fullpath, tokens) == -1) {
                    perror("execvp");
                    exit(EXIT_FAILURE);
                }
            } else {
                if (wait(&child_status) == -1) {
                    perror("wait");
                    exit(EXIT_FAILURE);
                }

                if (WIFEXITED(child_status) && WEXITSTATUS(child_status) != 0) {
                    fprintf(stderr, "Child process failed\n");
                }
            }

            if (flag == 1) {
                free(fullpath);
            }
        }
    }

    free(line);
    return 0;
}


