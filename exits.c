#include "shell.h"

/**
 * copyStringLimited - copies a string with a length limit
 * @destination: the destination string to be copied to
 * @source: the source string
 * @maxLength: the maximum number of characters to be copied
 * Return: the concatenated string
 */
char *copyStringLimited(char *destination, char *source, int maxLength)
{
	int sourceIndex, destinationIndex;
	char *result = destination;

	sourceIndex = 0;
	while (source[sourceIndex] != '\0' && sourceIndex < maxLength - 1)
	{
	destination[destinationIndex] = source[sourceIndex];
	sourceIndex++;
	destinationIndex++;
	}

	if (sourceIndex < maxLength)
	{
	int fillIndex = sourceIndex;
	while (fillIndex < maxLength)
	{
	destination[fillIndex] = '\0';
	fillIndex++;
	}
	}

	return (result);
}

/**
 * concatenateStringsLimited - concatenates two strings with a length limit
 * @firstString: the first string
 * @secondString: the second string
 * @maxLength: the maximum number of characters to be used
 * Return: the concatenated string
 */
char *concatenateStringsLimited(char *firstString, char *secondString, int maxLength)
{
	int firstIndex, secondIndex;
	char *result = firstString;

	firstIndex = 0;
	while (firstString[firstIndex] != '\0')
	firstIndex++;

	secondIndex = 0;
	while (secondString[secondIndex] != '\0' && secondIndex < maxLength)
	{
	firstString[firstIndex] = secondString[secondIndex];
	firstIndex++;
	secondIndex++;
	}

	if (secondIndex < maxLength)
	{
	firstString[firstIndex] = '\0';
	}

	return (result);
}

/**
 * findCharacter - locates a character in a string
 * @stringToSearch: the string to be parsed
 * @characterToFind: the character to look for
 * Return: a pointer to the memory area where the character is found in the string
 */
char *findCharacter(char *stringToSearch, char characterToFind)
{
	do
	{
	if (*stringToSearch == characterToFind)
	return (stringToSearch);
	}
	while (*stringToSearch++ != '\0');

	return (NULL);
}
