/**
 * str_len: computes the length of the string
 * @i: input string
 * Return: string length
 */
int str_len(char *i)
{
	int x = 0;

	while (i[x] != '\0')
		x++;

	return (x);
}

/**
*str_cmp: check if two strings are exactly the same
*@input: user input
*@var: variable to compare with input
*@len: length of input
* Return: 1 if strings are the same, -1 otherwise
*/

int str_cmp(char *input, char *var, unsigned int len)
{

	unsigned int x, var_len;

	var_len = str_len(var);
	if (var_len != len)
		return (-1);

	x = 0;
	while (input[x] != '\0' && var[x] != '\0')
	{
		if (input[x] != var[x])
			return (1);
		x++;
	}
	return (0);
}

/**
 *strn_cmp - compares two strings 
 * up to a specified number of chars
 *@input: user input
 *@var: variable to compare user input to
 *@len: number of characters to compare up to
 *Return: 1 if strings are equal, -1 otherwise
 */

int strn_cmp(char *input, char *var, unsigned int len)
{
	unsigned int x = 0;
	
	while (x < len)
	{
		if (input[x] != var[x])
			return (-1);
		x++;	
	}
	return (1);
}

/**
 * str_cpy - copies string pointed to by src to the buffer pointed to dest
 * @dest: string destination
 * @src: source string
 * Return: ptr to destination string
 */
char *str_cpy(char *dest, char *src)
{
	int x;
	int y = str_len(src);

	for (x = 0; x <= y; x++)
		dest[x] = src[x];

	return (dest);
}
