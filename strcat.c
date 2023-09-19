#include "main.h"
/**
 * _strcat - combines two strings
 * @dest: destination string
 * @src: source string
 *
 * Return: combined string
 */
char *_strcat(char *dest, const char *src)
{
	int i, j;

	i = _strlen(dest);
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
