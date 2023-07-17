#include "main.h"

/**
 * main - Entry point.
 * @ac: No. of CLI args.
 * @av: array of pointers to CLI args
 * Return: 0 always.
 */
int main(int ac, char *av[])
{
	char *cmd_line = NULL, **args = NULL;
	size_t size_line;
	pid_t child_pid;
	int status, i;

	(void) i;
	(void) ac;
	for (;;)
	{
		write(1, "#cisfun$ ", 9);
		if (getline(&cmd_line, &size_line, stdin) < 0)
			break;
		if (*cmd_line == EOF)
			break;
		cmd_line[strlen(cmd_line) - 1] = '\0';

		args = malloc(sizeof(char *) * 2);
		args[0] = malloc(sizeof(char) * (strlen(cmd_line) + 1));
		strcpy(args[0], cmd_line);
		args[1] = NULL;
		child_pid = fork();
		if (child_pid < 0)
			perror("Error: ");
		if (child_pid == 0)
		{
			execve(args[0], av, environ);
			perror(av[0]);
		}
		wait(&status);
		for (i = 0; i < 2; i++)
			free(args[i]);
	}
	free(args);
	free(cmd_line);
/*	write(1, "\n", 1); */
	exit(0);
}
