#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int engage(info_t *s);
int _delim(char c, char *dlm);
int _isalpha(int n);
int _atoi(char *c);
list_t *add_node(list_t **head, const char *str, int num);
list_t *conc_node(list_t **head, const char *str, int num);
size_t print_strlist(const list_t *h);
int delete_node(list_t **head, unsigned int index);
void free_list(list_t **ptrhead);
size_t lenlist(const list_t *c);
char **string_list(list_t *head);
size_t print_list(const list_t *h);
list_t *startnode(list_t *node, char *prefix, char c);
ssize_t nodeindex(list_t *head, list_t *node);

/**
 * struct ls_str - Linked list
 * @num: Number argument
 * @str: String argument
 * @next: pointer to next node
 */

typedef struct ls_str
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 * struct pushinfo - Function arguments
 * @readcmd: Read line input
 * @env: Pointer to environment
 * @environ: Double pointer to address of env
 * @change_env: Check for change of env 
 */

typedef struct pushinfo
{
	int readcmd;
	list_t *env;
	char **environ;
	int change_env;
} info_t;

#endif
