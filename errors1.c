#include "shell.h"

/**
 * _stringToInteger - converts a string to an integer
 * @str: the string to be converted
 * Return: 0 if no numbers in the string, converted number otherwise,
 *         -1 on error
 */
int _stringToInteger(char *str)
{
	int index = 0;
	unsigned long int result = 0;

	if (*str == '+')
	str++;  /* TODO: why does this make main return 255? */
    
	for (index = 0; str[index] != '\0'; index++)
	{
	if (str[index] >= '0' && str[index] <= '9')
	{
	result *= 10;
	result += (str[index] - '0');
            
	if (result > INT_MAX)
	return (-1);
	}
	else
	{
return (-1);
	}
	}

	return ((int)result);
}

/**
 * printError - prints an error message
 * @info: the parameter and return info struct
 * @errorType: string containing specified error type
 * Return: None
 */
void printError(info_t *info, char *errorType)
{
	_eputs(info->fname);
	_eputs(": ");
	printDecimal(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(errorType);
}

/**
 * printDecimal - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the file descriptor to write to
 * Return: number of characters printed
 */
int printDecimal(int input, int fd)
{
	int (*writeCharacter)(char) = _putchar;
	int index, count = 0;
	unsigned int absoluteValue, current;

	if (fd == STDERR_FILENO)
	{
	writeCharacter = _eputchar;
	}
    
	if (input < 0)
	{
	absoluteValue = -input;
	writeCharacter('-');
	count++;
	}
	else
	{
	absoluteValue = input;
	}

	current = absoluteValue;

	for (index = 1000000000; index > 1; index /= 10)
	{
	if (absoluteValue / index)
	{
	writeCharacter('0' + current / index);
	count++;
	}
	current %= index;
	}

	writeCharacter('0' + current);
	count++;

	return (count);
}

/**
 * convertNumber - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * Return: string
 */
char *convertNumber(long int num, int base, int flags)
{
	static char *characterArray;
	static char buffer[50];
	char sign = 0;
    	char *ptr;
	unsigned long number = num;
	
	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
	number = -num;
	sign = '-';
	}

	characterArray = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do
	{
	*--ptr = characterArray[number % base];
	number /= base;
	}
	while (number != 0);
	if (sign)
	{
	*--ptr = sign;
	}
    
	return (ptr);
}

/**
 * removeComments - function replaces the first instance of '#' with '\0'
 * @buffer: address of the string to modify
 * Return: Always 0
 */
void removeComments(char *buffer)
{
	int index;

	for (index = 0; buffer[index] != '\0'; index++)
	{
	if (buffer[index] == '#' && (!index || buffer[index - 1] == ' '))
	{
	buffer[index] = '\0';
	break;
	}
	}
}
