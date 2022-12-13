#include "shell.h"

/**
 * gt - calls getline and counts the number of argcv
 * @S_args: a poniter to a string
 * Return: the number of argcv , (-1) or (-2) if it fails
 */

int gt(char **S_args)
{
	char *buff = NULL;
	size_t bufflen = 0;
	int res = 0;
	int gtres;

	gtres = getline(&buff, &bufflen, stdin);
	if (gtres == -1)
	{
		free(buff);
		return (-1);
	}

	*S_args = _strdup(buff);
	if (*S_args == NULL)
	{
		free(buff);
		return (-1);
	}
	res = tokcont(buff, "\n\t ");
	if (res == -1)
	{
		die_free("SS", buff, *S_args);
		return (-2);
	}
	else
	{
		free(buff);
		return (res);
	}

}
/**
 * Pfind - verifies if the command is in the PATH.
 * @command: command to verfy
 * Return: (0) on success, (-1) if it fails
 */

int Pfind(char **command)
{
	char **Path, *Pathcpy, *token, *cpy;
	int i = 0, cont = 0;
	struct stat pet;

	Pathcpy = _getenv("PATH");
	if (Pathcpy == NULL)
		return (-1);

	cpy = _strdup(Pathcpy);
	if (cpy == NULL)
		return (-1);

	token = strtok(cpy, ":");
	while (token)
	{
		cont++;
		token = strtok(NULL, ":");
	}

	free(cpy);
	cpy = NULL;

	Path = malloc(sizeof(char *) * (cont + 1));
	if (Path == NULL)
		return (-1);

	token = strtok(Pathcpy, ":");
	while (token)
	{
		Path[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	Path[cont] = NULL;
	for (i = 0; i < cont; i++)
	{
		cpy = malloc(_strlen(Path[i]) + _strlen(*command) + 2);
		if (cpy == NULL)
		{
			free(Path);
			return (-1);
		}
		_strcpy(cpy, Path[i]);
		_strcat(cpy, "/");
		_strcat(cpy, *command);
		if (stat(cpy, &pet) == 0)
		{
			*command = cpy;
			free(Path);
			free(Pathcpy);
			return (0);
		}
		free(cpy);
		cpy = NULL;
	}
	free(Pathcpy);
	free(Path);
	return (-1);
}

/**
 * _getenv - finds a enviroment variable
 *
 * @name : name of the variable to find
 *
 * Return: A pointer to a duplicate of the variable or NULL if it fails
 */

char *_getenv(const char *name)
{
	char *envcpy, *tok, *aux;
	int i;

	for (i = 0; environ[i]; i++)
	{
		envcpy = _strdup(environ[i]);
		if (envcpy == NULL)
			return (NULL);

		tok = strtok(envcpy, "=");

		if (_strcmp(tok, name) == 0)
		{
			tok = strtok(NULL, "=");
			break;
		}
		free(envcpy);
		tok = NULL;
	}
	aux = _strdup(tok);
	free(envcpy);
	return (aux);
}

/**
 * die_free - releases the memory
 *
 * @typearg: type of args to free
 * @...: variable args
 *
 * Return: (0) if succed (-1) fi it fails
 */

int die_free(char *typearg, ...)
{
	int i, len;
	va_list n_para;

	len = _strlen(typearg);

	va_start(n_para, typearg);

	for (i = 0; i < len; i++)
	{
		if (typearg[i] == 'P')
			free(va_arg(n_para, char **));

		else if (typearg[i] == 'S')
			free(va_arg(n_para, char *));

		else
		{
			printf("ERROR\n\n");
			return (-1);
		}
	}
	return (0);
}

/**
 * tokcont - count nº of tokens
 *
 * @str : str to count
 * @delim: delimiter to tokenize
 *
 *Return: (-1) if it fails, number of tok plus 1 if succed
 */

int tokcont(char *str, char *delim)

{
	char *tok;
	int cont = 0;

	tok = strtok(str, delim);

	if (!tok)
		return (-1);

	while (tok)
	{
		cont++;
		tok = strtok(NULL, delim);
	}
	return (cont +	1);
}

