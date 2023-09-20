#include "main.h"
/**
 * execute - executes the command
 * @command: string or word which is a command in shell
 * @name: name of program
 * @args: array of command and arguments
 *
 * Return: 0 (success) or 1(fail)
 */
int execute(char *command, char *name, char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(command, args, environ) == -1)
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
	char *line = NULL, *name, *command, *fullPath;
	size_t i = 0;
	const char *dls = {" \n"};
	char **args;
	int idx;

	(void)ac;
	name = av[0];
	printf("($) ");
	while (1)
	{
		if (getline(&line, &i, stdin) == -1)
		{
			printf("\n");
			break;
		}
		args = tokenStore(line, dls);
		if (args == NULL)
			return (1);
		command = args[0];
		if (_strchr(command, '/'))
			execute(command, name, args);
		else if (_strcmp(command, "exit") == 0)
			break;
		else
		{
			fullPath = find_command(command);
			if (fullPath != NULL)
				execute(fullPath, name, args);
			else
				perror(name);
		}
		for (idx = 0; args[idx] != NULL; idx++)
		{
			free(args[idx]);
		}
		free(args);
		printf("($) ");
	}
	free(line);
	return (0);
}
