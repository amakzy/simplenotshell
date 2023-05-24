#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

/* for read/write buffers */
#define BUFFER_SIZE 1024
#define READ_BUF_SIZE 1024
#define WRITE_BUFFER_SIZE 1024
#define BUF_FLUSH 0

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

typedef struct
{
	char *arg;
	char *cmd_buf;
	int linecount_flag;
	int histcount;
	int cmd_buf_type;
} info_t;

/*func getline.c */
ssize_t line_input(info_t *inf);
ssize_t input_buffer(info_t *inf, char *buffer, size_t *len);
void ccblocker(int snom);
void check_name(info_t *, char *, size_t *, size_t *, size_t len);
int is_name(info_t *, char *, size_t *);
void rmv_comment(char *buffer);
void make_history_list(info_t *inf, char *buffer, int);
void _putchar(int );
void _puts(const char *);

#endif
