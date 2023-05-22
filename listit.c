#include "main.h"

/**
 * add_node - Starting node on list
 * @head: Head of node
 * @str: String argument
 * @num: Number argument
 * Return: List Size
 */

list_t *add_node(list_t **head, const char *str, int num)
{
	list_t *newnode;
	if (!head)
		return (NULL);
	newnode = malloc(sizeof(list_t));
	if (!newnode)
		return (NULL);
	memset((void *)newnode, 0, sizeof(list_t));
	newnode->num = num;
	if (str)
	{
		newnode->str = strdup(str);
		if (!newnode->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	newnode->next = *head;
	*head = newnode;
	return (newnode);
}

/**
 * conc_node - Ending node
 * @head: Head of node
 * @str: String argument
 * @num: Integer argument
 * Return: List size
 */

list_t *conc_node(list_t **head, const char *str, int num)
{
	list_t *newnode, *node;
	if (!head)
		return (NULL);
	node = *head;
	newnode = malloc(sizeof(list_t));
	if (!newnode)
		return (NULL);
	memset((void *)newnode, 0, sizeof(list_t));
	newnode->num = num;
	if (str)
	{
		newnode->str = strdup(str);
		if (!newnode->str)
		{
			free(newnode);
			return (NULL);
		}
	} if (
			node)
	{
		while (node->next)
			node = node->next;
		node->next = newnode;
	}
	else
		*head = newnode;
	return (newnode);
}

/**
 * print_strlist - Print string list
 * @h: Pointer to node at index
 * Return: Size of list
 */

size_t print_strlist(const list_t *h)
{
	size_t i = 0;
	while (h)
	{
		puts(h->str ? h->str : "(nil)");
		puts("\n");
		h = h->next;
		i++;
	} return (
			i);
}

/**
 * delete_node - Delete node at index
 * @head: Pointer to node at index
 * @index: Delete node at index
 * Return: 1 or 0 upon success
 */

int delete_node(list_t **head, unsigned int index)
{
	list_t *node, *prenode;
	unsigned int i = 0;
	if (!head || !*head)
		return (0);
	if (!index)
	{
		node = *head;
		*head = (*head)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *head;
	while (node)
	{
		if (i == index)
		{
			prenode->next = node->next;
			free(node->str);
			free(node);
			return (1);
		} i++;
		prenode = node;
		node = node->next;
	} return (
			0);
}

/**
 * free_list - Free node
 * @ptrhead: New address to node
 * Return: Always 0
 */

void free_list(list_t **ptrhead)
{
	list_t *node, *next_node, *head;
	if (!ptrhead || !*ptrhead)
		return;
	head = *ptrhead;
	node = head;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*ptrhead = NULL;
}
