#include "main.h"
/**
 * executeCommand - executes the command
 * @command: string or word which is a command in shell
 * @name: name of program
 *
 * Return: 0 (success) or 1(fail)
 */
int executeCommand(char *command, char *name)
{
	char *argv[2], *envp[] = {NULL};
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Fork error");
		return (1);
	}
	if (child_pid == 0)
	{
		argv[0] = command;
		argv[1] = NULL;
		if (execve(command, argv, envp) == -1)
		{
			perror(name);
			exit(3);
		}
	}
	else
		wait(&status);
	return (0);
}
/**
 * main - main function
 * @ac: argument count
 * @av: argument
 * Return: 0
 */
int main(int ac, char *av[])
{
	char *line = NULL, *tokens, *name;
	size_t i = 0;
	const char *dls = {"\n"};

	(void)ac;
	name = av[0];
	printf("($) ");
	while (getline(&line, &i, stdin) != -1)
	{
		tokens = strtok(line, dls);
		if (tokens == NULL)
		{
			perror("Token error");
			return (1);
		}
		executeCommand(tokens, name);
		printf("($) ");
	}
	return (0);
}
