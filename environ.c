#include "shell.h"

/**
 * _myenv - prints the current environment
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myenv(info_t *info)
{
	print_environment(info->env);
	return (0);
}

/**
 * _getenv - gets the value of an environment variable
 * @info: Structure containing potential arguments.
 * @name: The environment variable name
 * Return: The value of the environment variable, or NULL if not found
 */
char *_getenv(info_t *info, const char *name)
{
	list_t *current_node = info->env;
	char *value;

	while (current_node)
	{
	value = starts_with(current_node->str, name);
	if (value && *value)
		return (value);
	current_node = current_node->next;
	}

	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable or modify an existing one
 * @info: Structure containing potential arguments.
 * Return: Always 0 on success, 1 on error
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
	_eputs("Incorrect number of arguments\n");
	return (1);
	}

	if (_set_environment_variable(info, info->argv[1], info->argv[2]))
	return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments.
 * Return: Always 0 on success, 1 on error
 */
int _myunsetenv(info_t *info)
{
	int i;

	if (info->argc == 1)
	{
	_eputs("Too few arguments.\n");
	return (1);
	}

	for (i = 1; i < info->argc; i++)
	_unset_environment_variable(info, info->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates the environment linked list
 * @info: Structure containing potential arguments.
 * Return: Always 0 on success
 */
int populate_env_list(info_t *info)
{
	size_t i;

	for (i = 0; environ[i]; i++)

	add_environment_variable_end(&(info->env), environ[i], 0);
}
	return (0);
}
