#include "shell.h"

/**
 * _eputs - prints an input string to stderr
 * @str: The string to be printed
 */
void _eputs(char *str)
{
	if (!str)
	return;
    
	for (int index = 0; str[index] != '\0'; index++)
	{
	_eputchar(str[index]);
	}
}

/**
 * _eputchar - writes a character to stderr
 * @c: The character to print
 *
 * Return: On success, 1; on error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char c)
{
	static int buffer_index;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
	{
	write(2, buffer, buffer_index);
	buffer_index = 0;
	}
    
	if (c != BUF_FLUSH)
	{
	buffer[buffer_index++] = c;
	}

	return (1);
}

/**
 * _putfd - writes a character to the given file descriptor
 * @c: The character to print
 * @fd: The file descriptor to write to
 *
 * Return: On success, 1; on error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
	static int buffer_index;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || buffer_index >= WRITE_BUF_SIZE)
	{
	write(fd, buffer, buffer_index);
	buffer_index = 0;
	}

	if (c != BUF_FLUSH)
	{
	buffer[buffer_index++] = c;
	}

	return (1);
}

/**
 * _putsfd - prints an input string to the given file descriptor
 * @str: The string to be printed
 * @fd: The file descriptor to write to
 *
 * Return: The number of characters written
 */
int _putsfd(char *str, int fd)
{
	int char_count = 0;

	if (!str)
	return (0);

	for (int index = 0; str[index] != '\0'; index++)
	{
	char_count += _putfd(str[index], fd);
	}

	return (char_count);
}
