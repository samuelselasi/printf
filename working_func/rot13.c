#include "main.h"

/**
 * rot13 - convert to rot13 encryption
 * @str: the string
 * Return: encrypted string
 */

char *rot13(char *str)
{
	char input[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char key[] = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	long int i, j, len;
	char *copy;

	if (str == NULL)
		return (null());
	len = _strlen(str);
	copy = malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	copy[len] = 0;
	i = 0;
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	for (i = 0; i < len; i++)
	{
		for (j = 0; input[j] != '\0'; j++)
		{
			if (copy[i] == input[j])
			{
				copy[i] = key[j];
				break;
			}
		}
	}

	return (copy);
}
