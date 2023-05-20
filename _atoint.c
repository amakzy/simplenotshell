#include "main.h"

/**
 * engage - Check if shell is in i mode
 * @s: struct pointer
 * Return: 1 or 0
 */

int engage(info_t *s)
{
	return (isatty(STDIN_FILENO) && s->readcmd <= 2);
}

/**
 * _delim - Check for delimeter
 * @c: Character argument
 * @dlm: Pointer to delimeter
 * Return: 1 or 0
 */

int _delim(char c, char *dlm)
{
	while (*dlm)
		if (*dlm++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - Check for alphabet
 * @n: Input
 * Return: 1 or 0
 */

int _isalpha(int n)
{
	if ((n >= 'a' && n <= 'z') || (n >= 'A' && cn <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - Converts alphabets to numbers
 * @c: String argument
 * Return: 0
 */

int _atoi(char *c)
{
	int i, s = 1, f = 0, o;
	unsigned int r = 0;

	for (i = 0; c[i] != '\0' && f != 2; i++)
	{
		if (c[i] == '-')
			s *= -1;
		if (c[i] >= '0' && c[i] <= '9')
		{
			f = 1;
			r *= 10;
			r += (c[i] - '0');
		}
		else if (f == 1)
			f = 2;
	}
	if (s == -1)
		o = -r;
	else
		o = r;
	return (o);
}
