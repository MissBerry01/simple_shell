#include "shell.h"

/**
 * retrieveEnvironment - returns a copy of the environment as a string array
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **retrieveEnvironment(info_t *info)
{
	if (!info->environment || info->environmentChanged)
	{
	info->environment = listToStringArray(info->environmentList);
	info->environmentChanged = 0;
	}

	return (info->environment);
}

/**
 * removeEnvironmentVariable - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: 1 on delete, 0 otherwise
 * @variable: the string representing the environment variable
 */
int removeEnvironmentVariable(info_t *info, char *variable)
{
	list_t *currentNode = info->environmentList;
	size_t index = 0;
	char *property;
	
	if (!currentNode || !variable)
	return (0);

	while (currentNode)
	{
	property = startsWith(currentNode->str, variable);
	if (property && *property == '=')
	{
	info->environmentChanged = deleteNodeAtIndex(&(info->environmentList), index);
	index = 0;
	currentNode = info->environmentList;
	continue;
	}
	currentNode = currentNode->next;
	index++;
	}
	return (info->environmentChanged);
}

/**
 * setEnvironmentVariable - Initialize a new environment variable or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @variable: the string representing the environment variable
 * @value: the string representing the environment variable value
 * Return: Always 0
 */
int setEnvironmentVariable(info_t *info, char *variable, char *value)
{
	char *buffer = NULL;
	list_t *node;
	char *property;

	if (!variable || !value)
	return (0);

	buffer = malloc(strlen(variable) + strlen(value) + 2);
	if (!buffer)
	return (1);
	strcpy(buffer, variable);
	strcat(buffer, "=");
	strcat(buffer, value);
	node = info->environmentList;
	while (node)
	{
	property = startsWith(node->str, variable);
	if (property && *property == '=')
	{
	free(node->str);
	node->str = buffer;
	info->environmentChanged = 1;
	return (0);
	}
	node = node->next;
	}
	addNodeEnd(&(info->environmentList), buffer, 0);
	free(buffer);
	info->environmentChanged = 1;
	return (0);
}
