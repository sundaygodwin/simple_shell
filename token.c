#include "main.h"
/**
 * tokenStore - tokenises and allocates
 * @line: line read from the command line
 * @dls: delimiters
 *
 * Return: double pointer
 */
char **tokenStore(char *line, const char *dls)
{
	char *tokens;
	char **args = NULL;
	int count;

	tokens = strtok(line, dls);
	if (tokens == NULL)
	{
		perror("Token error");
		return (NULL);
	}
	count = 0;
	while (tokens != NULL)
	{
		args = realloc(args, (count + 1) * sizeof(char *));
		if (args == NULL)
			return (NULL);
		args[count] = _strdup(tokens);
		if (args[count] == NULL)
			return (NULL);
		count++;
		tokens = strtok(NULL, dls);
	}
	args = realloc(args, (count + 1) * sizeof(char *));
	if (args == NULL)
		return (NULL);
	args[count] = NULL;
	return (args);
}
