#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>

int engage(info_t *s);
int _delim(char c, char *dlm);
int _isalpha(int n);
int _atoi(char *c);

/**
 * struct pushinfo - Function arguments
 * @readcmd: Read line input
 */

typedef struct pushinfo
{
	int readcmd;
} info_t;

#endif
