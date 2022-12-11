#include "shell.h"



int main(void)
{
	char **argcv = NULL;
	char **S_args = NULL, **command = NULL, *token = NULL;
	struct stat pet;
	int res, id, i, x = 0, boolean, status;
	
	while (1)
	{	
		boolean = 0;
		i = 0;
		x++;

		command = malloc(sizeof(char *));
		if (command == NULL)
			return (-1);

		S_args = malloc(sizeof(char *));
		if (S_args == NULL)
		{
			free(command);
			return(-1);
        	}
		
		if (isatty(STDIN_FILENO) == 1)
			printf("$ ");

		res = gt(S_args);

		if (res == -1)
		{
			if (isatty(STDIN_FILENO) == 1)
			{
				free(command);
				free(S_args);
				return (-1);
			}
			if (isatty(STDIN_FILENO) == 0)
			{
				printf("\n");
				free(command);
				free(S_args);
				continue;
			}
		}
		argcv = malloc(sizeof(char *) * res);

		if (argcv == NULL)
		{
			free(*S_args);
			free(S_args);
			free(command);
			return(-1);
		}

		token = strtok(*S_args," \n\t");

		if (strcmp(token, "exit") == 0)
		{
			free(*S_args);
			free(S_args);
			free(command);
			free(argcv);
			return (0);
		}

		while (token)
		{
			argcv[i] = token;
			token = strtok(NULL," \n\t");
			i++;
		}
			
		argcv[res - 1] = NULL;

		if ((stat(argcv[0],&pet)) != 0)
		{
			*command = argcv[0];
			if ((Pfind(command)) == 0)
			{
				boolean = 1;
				argcv[0] = *command;
	
			}
			else
			{
				if (argcv[0] != NULL)
					printf("$: %d: %s: not found\n", x, *command);
				free(*S_args);
				free(S_args);
				free(command);
				free(argcv);
				continue;
			}
		}
		id = fork();

		if (id == -1)
		{
			free(command);
			free(argcv);
			free(*S_args);
			free(S_args);
			return(-1);
		}
		if (id == 0)
		{
			if (execve(argcv[0],argcv,environ) == -1)
			{
				perror(argcv[0]);
				return (0);
			}
		}
		else
		{
			wait(&status);
			free(argcv);
			if (boolean == 1)
				free(*command), *command = NULL;
			free(command);
			free(*S_args);
			free(S_args);
		}
	}
}
