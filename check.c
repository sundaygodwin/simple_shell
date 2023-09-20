#include "main.h"
/**
 * check - checks if the command exists anf runs it
 * @command: command to be checked
 * @name: name of the program
 * @args: full argument
 * Return: none
 */
void check(char *command, char *name, char *args[])
{
	char *fullPath;

	if (_strcmp(command, "exit") == 0)
		exit(0);
	if (_strchr(command, '/'))
		execute(command, name, args);
	else
	{
		fullPath = find_command(command);
		if (fullPath != NULL)
			execute(fullPath, name, args);
		else
			perror(name);
	}
}
