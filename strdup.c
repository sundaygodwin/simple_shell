#include "main.h"
/**
 * _strdup - creates a duplicate of a string
 * @str: string
 *
 * Return: pointer to a duplicated string
 */
char *_strdup(char *str)
{
	int i, len;
	char *dup;

	len = _strlen(str);
	if (str == NULL)
		return (NULL);
	dup = (char *)malloc(len + 1 * sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
