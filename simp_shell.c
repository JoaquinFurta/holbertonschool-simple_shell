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
			return (-1);
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
		}
		argcv = malloc(sizeof(char *) * res);

		if (argcv == NULL)
		{
			die_free("SPP", *S_args, S_args, command);
			return (-1);
		}

		token = strtok(*S_args," \n\t");

		if (_strcmp(token, "exit") == 0)
		{
			die_free("SPPP", *S_args, S_args, command, argcv);
			return (0);
		}

		while (token)
		{
			argcv[i] = token;
			token = strtok(NULL, " \n\t");
			i++;
		}

		argcv[res - 1] = NULL;

		if ((stat(argcv[0], &pet)) != 0)
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
				die_free("SPPP", *S_args, S_args, command, argcv);
				continue;
			}
		}
		id = fork();

		if (id == -1)
		{
			die_free("PPSP", command, argcv, *S_args, S_args);
			return (-1);
		}
		if (id == 0)
		{
			if (execve(argcv[0], argcv, environ) == -1)
			{
				perror(argcv[0]);
				exit(0);
			}
		}
		else
		{
			wait(&status);
			if (boolean == 1)
				free(*command), *command = NULL;
			die_free("PPSP", argcv, command, *S_args, S_args);
		}
	}
}
