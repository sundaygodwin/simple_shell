#include "main.h"
/**
 * main - main function
 * @ac: argument count
 * @av: argument
 * Return: 0
 */
int main(int ac, char *av[])
{
	char *line = NULL, *name, *command;
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
		check(command, name, args);
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
