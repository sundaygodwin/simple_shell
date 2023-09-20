#include "main.h"
/**
 * find_command - finds command in the PATH
 * @command: token containing the command
 *
 * Return: string if found or NULL if not found
 */
char *find_command(char *command)
{
	const char *dls = ":";
	char *path = getenv("PATH");
	char *fullPath = NULL, *tokens, *copy;
	int len;

	if (path == NULL)
	{
		perror("PATH Error");
		return (NULL);
	}
	copy = _strdup(path);
	if (copy == NULL)
		return (NULL);
	tokens = strtok(copy, dls);
	while (tokens != NULL)
	{
		len = _strlen(tokens) + 1 + _strlen(command) + 1;
		fullPath = (char *)malloc(len);
		if (fullPath != NULL)
		{
			_strcpy(fullPath, tokens);
			_strcat(fullPath, "/");
			_strcat(fullPath, command);
			if (access(fullPath, X_OK) == 0)
			{
				free(copy);
				return (fullPath);
			}
			free(fullPath);
		}
		tokens = strtok(NULL, dls);
	}
	free(copy);
	return (NULL);
}
