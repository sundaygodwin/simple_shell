#include "main.h"
/**
 * _strcpy - copies string from src to dest
 * @dest: destination string
 * @src: source string
 *
 * Return: pointer
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (ptr);
}
