#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Variables declarations */
extern char *environ[];

/* Functions prototypes */
ssize_t _getline(char **line, size_t *n, int fd);
int _strlen(char *);
char *_strcpy(char *, const char *);
#endif
