#include "shell.h"

/**
 * _strcat - concatenates two strings
 * @src: first string
 * @dest: second string
 * Return: NUll if it fails , the new string concateneted if success
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int contador = 0;
	int largo = 0;

	for (i = 0; src[i] != '\0'; i++)
		contador++;

	for (i = 0; dest[i] != '\0'; i++)
		largo++;


	for (i = 0; i < contador; i++)
		dest[i + largo] = src[i];

	dest[largo + contador] = '\0';
	return (dest);
}
/**
 * _strcpy - copies a string
 * @src: string to cpy
 * @dest: string to return
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;
	int contador = 0;

	for (i = 0; src[i] != '\0'; i++)
		contador++;

	for (i = 0; i < contador; i++)
		dest[i] = src[i];
	dest[contador] = '\0';
	return (dest);
}

/**
 * _strdup - creates an array of chars
 * @str: char
 * Return: a copy of the stirng
 */
char *_strdup(char *str)
{
	int i, mem = 0;
	char *p;

	if (str == NULL)
		return ('\0');

	while (str[mem] != '\0')
		mem++;

	p = malloc(mem + 2);

	if (p == NULL)
		return (NULL);

	for (i = 0; i < mem; i++)
		p[i] = str[i];
	p[mem] = '\0';
	return (p);
}

/**
 * _strlen - counts the length of a string
 * @s : string
 * Return: length of the string
 */
int _strlen(char *s)
{
	int i;
	int contador;

	contador = 0;

	for (i = 0 ; s[i] != '\0'; i++)
		contador++;
	return (contador);
}

/**
 * _strcmp - compares two strings
 * @s1: string_1
 * @s2: string_2
 * Return: (0) if strings are equal, (<0) if str_1 > str_2, or (>0) otherwise
 */
int _strcmp(const char *s1, const  char *s2)
{
	while ((*s1 && *s2) != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}
