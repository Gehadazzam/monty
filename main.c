#include "monty.h"
args_t args = {NULL, NULL};
/**
*main - entry point to the interpreter
*@argc: number of arguments
*@argv: array of arguments
*Return: 0
*/
int main(int argc, char **argv)
{
int file_d;
char *buf = NULL;
size_t buf_size = 0;
ssize_t read_line = 1;
unsigned int count = 0;
stack_t *stack = NULL;
FILE *file;
args_t *args;
	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	file_d = open(argv[1], O_RDONLY);
	if (file_d == -1)
		fprintf(stderr, "Error: can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	file = fdopen(file_d, "r");
	if (file == NULL)
{
		fprintf(stderr, "Error: can't open file %s\n", argv[1]);
		close(file_d), exit(EXIT_FAILURE);
}
	args = malloc(sizeof(args_t));
	if (args == NULL)
{
		fprintf(stderr, "Error: Failed to allocate memory for args\n");
		exit(EXIT_FAILURE);
}
	while (read_line > 0)
{
		read_line = getline(&buf, &buf_size, file);
		args->buf = buf, count++;
		if (read_line > 0)
			if (check_func(buf, &stack, count, file_d) == 1)
{
				fprintf(stderr, "L%d: unknown instruction %s\n", count, args->buf);
				free_all(buf, stack, args, file, file_d);
				exit(EXIT_FAILURE);
}
}
	free_all(buf, stack, args, file, file_d);
	return (0);
}
