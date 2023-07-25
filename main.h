#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER 1024
#define PROMPT "$"

#define ERR_MALLOC "Failed to malloc space"
#define ERR_FORK "Fork failure, unable to create child process"
#define ERR_PATH "No such file or directory \n"

extern char **environ;

/**
 * struct list_s - variables LL
 * @val: value
 * @nxt: pointer to next node
 *
 * Description: linked list struct for variables.
**/
typedef struct list_s
{
	char *value;
	struct list_s *next;
} list_s;

/**
 * struct built_s - builtins LL
 * @name: builtin name
 * @p: ptr to function
 *
 * Description: struct for builtin functions.
**/
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;

char *get_line(FILE *fp);
char **token_maker(char *str);
char *search_(char *cmd, char *fpath, char *path);
int child(char *fpath, char **tkns);
void cue(int fd, struct stat buff);
void print_error(int err);

/*builtins*/
int print_env(void);
int exit_shell(void);
int exec_builtin(char **tkns);
int num_builtins(built_s builtin[]);

/*Helper functions*/
char *str_cpy(char *dest, char *src);
int str_cmp(char *input, char *var, unsigned int len);
int strn_cmp(char *input, char *var, unsigned int len);
int str_len(char *i);
void _puts(char *str);

char **cpy_env(char **cpy_environ, unsigned int len_env);
char *get_env(const char *env_var);
list_s *pathlist(char *var, list_s *head);

void free_all(char **tkns, char *path, char *line, char *fpath, int flag);
void free_double(char **array, unsigned int len);

#endif /* MAIN_H */

