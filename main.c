#include "main.h"
/**
 * handle_prompt - handles signals and writes the prompt
 * @sig: signal
 *
 * Return: nothing
 */

void handle_prompt_sig(int sig)
{
	(void) sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * main - Entry point
 * @argc: arg count
 * @argv: arg vector
 * @env: environment variables
 * 
 * Return: 0 (success), 1 (failure)
 */

int main(int argc, char **argv, char **env)
{
	char *buffer = NULL;
	size_t input_len = 0;
	ssize_t num_chars;
	const char *cd_cmd = "cd";
	const char *prompt = "$";
	const char *exit_cmd = "exit";
	const char *env_cmd = "env";
	int count = 0;

	if (isatty(STDIN_FILENO))
	{
		write(STD_FILENO, prompt, 2);
	}

	signal(SIGINT, handle_prompt_sig);

	while ((num_chars = getline(&buffer, &input_len, stdin)) != -1)
	{
		if (num_chars == EOF)
			handleEOF(buffer);

		count ++;

		char **cmds = _strtok(buffer);

		if (_strcmp(cd_cmd, cmds[0]))
		{
			if (change_dir(cmds[1]) < 0)
				print_err(cmds[1]);
			continue;
		}

		pid_t child = fork();

		if (child == -1)
			handle_fork_failure();

		if (child == 0)
		{

			if (cmds == NULL)
				handle_null_cmd(buffer);
			else if ( _strcmp(env_cmd, cmds[0]))
				print_environment(buffer, cmds, env);
			else if (_strcmp(exit_cmd, cmds[0]))
				exit_shell(buffer, cmds);
			else if (stat(cmds[0], &fileStat) == 0)
				execute_cmd(cmds[0], cmds);
			else
				search_path_for_cmd(cmds, buffer, env, argv, count);
		}
		else
		{
			int status;
			wait(&status);

			if (cmds == NULL)
				free_mem(buffer, cmds);
			else if (_strcmp(exit_cmd, cmds[0]))
				exit_shell(buffer, cmds);
			else
				free_mem(buffer, cmds);
		}

		input_len = 0;
		buffer = NULL;

		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, prompt, 2);
	}

	free(buffer);

	return EXIT_SUCCESS;




