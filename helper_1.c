#include "shell.h"

/**
 *  * _strcmp - compare two strings
 *   * @first: first string to be compared
 *    * @second: second string to be compared
 *     *
 *      * Return: difference of the two strings
 *       */
int _strcmp(const char *first, const char *second)
{
	return strcmp(first, second);
}

/**
 *  * _strcat - concatenates two strings
 *   * @destination: string to be concatenated to
 *    * @source: string to concatenate
 *     *
 *      * Return: address of the new string
 *       */
char *_strcat(const char *destination, const char *source)
{
	size_t len_dest = strlen(destination);
	size_t len_source = strlen(source);
	char *new_string = malloc(len_dest + len_source + 1);

	if (new_string == NULL)
		return NULL;

	strcpy(new_string, destination);
	strcat(new_string, source);

	return new_string;
}

/**
 *  * _strspn - gets the length of a prefix substring
 *   * @str1: string to be searched
 *    * @str2: string to be used
 *     *
 *      * Return: number of bytes in the initial segment of str1 which are part of str2
 *       */
size_t _strspn(const char *str1, const char *str2)
{
	return strspn(str1, str2);
}

/**
 *  * _strcspn - computes segment of str1 which consists of characters not in str2
 *   * @str1: string to be searched
 *    * @str2: string to be used
 *     *
 *      * Return: index at which a char in str1 exists in str2
 *       */
size_t _strcspn(const char *str1, const char *str2)
{
	return strcspn(str1, str2);
}

/**
 *  * _strchr - locates a char in a string
 *   * @s: string to be searched
 *    * @c: char to be checked
 *     *
 *      * Return: pointer to the first occurrence of c in s
 *       */
char *_strchr(const char *s, int c)
{
	return strchr(s, c);
}

