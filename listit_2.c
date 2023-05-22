#include "main.h"

/**
 * lenlist - Length of list
 * @c: Pointer to node at index
 * @Return: List size
 */

size_t lenlist(const list_t *c)
{
	size_t i = 0;
	while (c)
	{
		c = c->next;
		i++;
	} return (i);
}

/**
 * string_list - List of strings in struct element
 * @head: Node at index
 * Return: string array
 */

char **string_list(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;
	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}
		str = strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}

/**
 * print_list - Print list elements
 * @h: Pointer to node at index
 * Return: List size
 */

size_t print_list(const list_t *h)
{
	size_t i = 0;
	while (h)
	{
		puts(convert_number(h->num, 10, 0));
		putchar(':');
		putchar(' ');
		puts(h->str ? h->str : "(nil)");
		puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * startnode - Node starting with a prefix
 * @node: Head node
 * @prefix: Node containing specific string
 * @c: Char of next prefix
 * Return: Node or void
 */

list_t *startnode(list_t *node, char *prefix, char c)
{
	char *p = NULL;
	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	} 
	return (NULL);
}

/**
 * nodeindex - State node index
 * @head: Node at index
 * @node: Pointer to node
 * Return: Node index or return -1
 */

ssize_t nodeindex(list_t *head, list_t *node)
{
	size_t i = 0;
	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	} return (-1);
}
