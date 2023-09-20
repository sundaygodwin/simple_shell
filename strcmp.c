#include "main.h"
/**
 * _strcmp - compares two strings
 * @str: string to be compared
 * @s: string to be used to compare with
 *
 * Return: 0 if equal, negative if less and positive if great
 */
int _strcmp(char *str, const char *s)
{
	while (*str != '\0' && *s != '\0')
	{
		if (*str != *s)
			return (*str - *s);
		str++;
		s++;
	}
	return (*str - *s);
}
