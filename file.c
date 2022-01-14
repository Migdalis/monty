#include "monty.h"

/**
 * read_file - Read a monty file
 * @filename: Name of the file
 * Return: 0 if it fails or 1
 */
int read_file(const char *filename)
{
	FILE *fo;
	char *line = NULL;
	int read = 0;
	unsigned int line_num = 1;
	size_t len = 0;
	stack_t *top = NULL;

	fo = fopen(filename, "r");
	if (fo == NULL)
		return (0);

	while ((read = getline(&line, &len, fo)) != -1)
	{
		get_instruction(line, line_num, &top);
		line_num++;
		/*printf("%s", line);*/
	}
	fclose(fo);
	free_stack(top);
	if (line)
		free(line);
	return (1);
}

/**
 *get_instruction - Tokenize each opcode instruction
 *@line: Instruction of the code
 *@line_num: Number of the instruction
 *@top: Top of the stack
 *
 * Return: 1 if it success
 **/
int get_instruction(char *line, unsigned int line_num, stack_t **top)
{
	char *strtok_inst;
	void (*fun_opcode)(stack_t **stack, unsigned int line_number);
	unsigned int n;

	strtok_inst = strtok(line, FILE_DELIM);
	while (strtok_inst != NULL)
	{
		fun_opcode = get_function(strtok_inst);
		if (fun_opcode == NULL)
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, strtok_inst);
			exit(EXIT_FAILURE);
		}
		else
		{
			if (strcmp(strtok_inst, "push") == 0)
			{
				n = _atoi(strtok(NULL, FILE_DELIM), line_num);
				fun_opcode(top, n);
			}
			else
				fun_opcode(top, line_num);
		}
		strtok_inst = strtok(NULL, FILE_DELIM);
	}
	return (1);
}

/**
 *get_function - Selects the correct function to a opcode
 *@code: Instrucion of the code
 *
 * Return: The correct function to do the code
 **/
void (*get_function(char *code))(stack_t **, unsigned int)
{
	int i;
	instruction_t functions[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}};

	for (i = 0; functions[i].f; i++)
	{
		if (strcmp(functions[i].opcode, code) == 0)
			return (functions[i].f);
	}
	return (functions[i].f);
}
