#include "monty.h"

/**
 *  * main - entry point for the Monty Bytecode Interpreter
 *   * @argc: argument count
 *    * @argv: argument vector
 *     *
 *      * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 *       */
int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	stack_t *stack = NULL;
	unsigned int line_number = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((read = getline(&line, &len, file)) != -1)
	{
		/*line_number++;*/
		line = strtok(argv[3], " \n\t");
		if (line && line[0] == '#')  /* Ignore lines starting with '#' */
			return (0);

		/* Parse and execute instructions */
		execute(line, &stack, line_number);
	}

	fclose(file);
	free(line);
	free_stack(stack);
	return EXIT_SUCCESS;
}
