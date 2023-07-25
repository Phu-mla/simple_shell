#include "main.h"
/**
 *search_ - searches for command in path
 *@cmd: command
 *@full_path: path of cmd
 *@path: variable of the full path
 * Return: ptr to full path
 */

char *search_(char *cmd, char *fpath, char *path)
{
	unsigned int cmd_len, path_len, original_len;
	char *cpy_path, *tok;

	cmd_len = str_len(cmd);
	original_len = str_len(path);
	cpy_path = malloc(sizeof(char) * original_len + 1);
	if (cpy_path == NULL)
	{
		print_error(1);
		return (NULL);
	}
	str_cpy(cpy_path, path);

	tok = strtok(cpy_path, ":");
	if (tok == NULL)
		tok = strtok(NULL, ":");
	while (tok != NULL)
	{
		path_len = str_len(tok);
		fpath = malloc(sizeof(char) * (path_len + cmd_len) +2);
		if (fpath == NULL)
		{	
			print_error(1);
			return (NULL);
		}
		str_cpy(fpath, tok);
		fpath[path_len] = '/';
		str_cpy(fpath + path_len + 1, cmd);
		fpath[path_len + cmd_len + 1] = '\0';
		if (access(fpath, X_OK) != 0)
		{
			free(fpath);
			fpath = NULL;
			tok = strtok(NULL, ":");
		}
		else
		   	break;
	}
	free(cpy_path);
	return (fpath);
}

		
		

		
