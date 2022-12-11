#include "shell.h"

/** 
 * gt - calls getline and counts the number of argcv
 * @S_args: a poniter to a string
 * Return: the number of argcv , (-1) if it fails
 */

int gt(char **S_args)
{
	char *buff = NULL;
	size_t bufflen = 0;
	ssize_t gtres = 0;
	char *token;
	int cont = 0;

	gtres = getline(&buff, &bufflen, stdin);
	if (gtres == -1)
	{
		free(buff);
		return(-1);
	}


	*S_args = strdup(buff);
	if (*S_args == NULL)
	{
		free(buff);
		return(-1);
	}

	token = strtok(buff,"\n ");
	while (token)
	{
		cont++;
		token = strtok (NULL,"\n ");
	}
	free(buff);
	return (cont + 1);
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
	
	Pathcpy = strdup(getenv("PATH"));

	cpy = strdup(Pathcpy);
	if (cpy == NULL)
		return(-1);
	
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
	while(token)
	{
		Path[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	Path[cont] = NULL;
	for (i = 0; i < cont; i++)
	{
		cpy = malloc(strlen(Path[i]) + strlen(*command) + 2);
		if (cpy == NULL)
		{
			free(Path);
			return(-1);
		}
		strcpy(cpy, Path[i]);
		strcat(cpy, "/");
		strcat(cpy, *command);
		if (stat(cpy, &pet) == 0)
		{
			*command = cpy;
			free(Path);
			free(Pathcpy);
			return(0);
		}
		free(cpy);
		cpy = NULL;
	} 
	free(Pathcpy);
	free(Path);
	return(-1);
}
