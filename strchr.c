#include "main.h"
/**
 * _strchr - locates character in the string
 * @str: string ti be searched through
 * @c: character to be found
 *
 * Return: string if found or NULL f not found
 */
char *_strchr(char *str, char c)
{
	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}
