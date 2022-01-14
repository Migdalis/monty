#include "monty.h"

/**
 *_atoi - Convert a string to integer
 *@s: String to convert
 *Description: Function for convert a string
 *Return: The number convert
 *
 **/
int _atoi(char *s, unsigned int line_num)
{
	unsigned int num;
	int i, f;

	num = 0;
	f = 1;
	for (i = 0; s[i]; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			num = (num * 10) + ((int)s[i] - 48);
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
		}
		else
		{
			printf("L%d: usage: push integer\n", line_num);
			exit(EXIT_FAILURE);
		}
		if (s[i] == '-')
			f = f * -1;
	}

	return (num * f);
}
