#include "monty.h"

vars var;
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/**
 * main - entry for monty program
 * @ac: argument count
 * @av: arguments vector
 * Return: 0 if success 1 if failed
 */

int main(int ac, char **av)
{
	char *opcode;

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	if (glob_vars(&var) != 0)
		return (EXIT_FAILURE);

	var.file = fopen(av[1], "r");
	
	if (!var.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		frees_all();
		return (EXIT_FAILURE);
	}

	while (getline(&var.buff, &var.tmp, var.file) != EOF)
	{
		opcode = strtok(var.buff, " \r\t\n");
		if (opcode != NULL)
		{
			if (opcode_call(&var, opcode) == EXIT_FAILURE)
			{
				frees_all();
				return (EXIT_FAILURE);
			}
		var.line_number++;
		}
	}
	frees_all();
	return (EXIT_SUCCESS);
}
