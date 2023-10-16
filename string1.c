#include "shell.h"

char *string_copy(char *destination, char *source)
{
	int i = 0;

	if (destination == source || source == 0)
	return destination;

	while (source[i])
	{
	destination[i] = source[i];
	i++;
	}
	destination[i] = '\0';
	return (destination);
}

char *string_duplicate(const char *str)
{
	int length = 0;
	char *result;

	if (str == NULL)
	return (NULL);

	while (*str++)
	length++;

	result = malloc(sizeof(char) * (length + 1));

	if (!result)
	return (NULL);

	for (length++; length--;)
	result[length] = *--str;

	return (result);
}

void string_print(char *str)
{
	int i = 0;

	if (!str)
	return;

	while (str[i] != '\0')
	{
	character_print(str[i]);
	i++;
	}
}

int character_print(char c) 
{
	static int i;
	static char buffer[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE) 
	{
	write(1, buffer, i);
	i = 0;
	}
	if (c != BUF_FLUSH)
	buffer[i++] = c;

	return (1);
}
