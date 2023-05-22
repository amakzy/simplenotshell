#include "main.h"

/**
 * get_env - Environ String copy
 * @c: Function character argument
 * Return: Always 0
 */

char **get_env(info_t *c)
{
	if (!c->environ || c->change_env)
	{
		c->environ = list_to_strings(c->env);
		c->change_env = 0;
	}
	return (c->environ);
}

/**
 * _unsetenv - Remove environment
 * @c: Function argument
 * @svar: String environ argument
 * Return: String environ
 */

int _unsetenv(info_t *c, char *svar)
{
	list_t *node = c->env;
	size_t i = 0;
	char *p;
	if (!node || !svar)
		return (0);
	while (node)
	{
		p = starts_with(node->str, svar);
		if (p && *p == '=')
		{
			c->change_env = delete_node(&(c->env), i);
			i = 0;
			node = c->env;
			continue;
		}
		node = node->next;
		i++;
	} return (
			c->change_env);
}

/**
 * _setenv - Set new env value
 * @c: Function argument
 * @svar: String env argument
 * @value: String value
 * Return: Always 0
 */

int _setenv(info_t *c, char *svar, char *val)
{
	char *buf = NULL;
	list_t *node;
	char *p;
	if (!svar || !val)
		return (0);
	buf = malloc(strlen(svar) + strlen(val) + 2);
	if (!buf)
		return (1);
	strcpy(buf, svar);
	strcat(buf, "=");
	strcat(buf, val);
	node = c->env;
	while (node)
	{
		p = starts_with(node->str, svar);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			c->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	conc_node(&(c->env), buf, 0);
	free(buf);
	c->env_changed = 1;
	return (0);
}
