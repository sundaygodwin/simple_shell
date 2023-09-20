#include "main.h"
/**
 * execute - execute the command
 * @command: string or word which is a command in shell
 * @name: name of program
 * @args: array of command and arguments
 *
 * Return: none
 */
void execute(char *command, char *name, char *args[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return;
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
}
