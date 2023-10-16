#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_history(info->history);
	return (0);
}

/**
 * unset_alias - unset an alias
 * @info: Parameter struct
 * @alias_str: The alias to unset
 * Return: Always 0 on success, 1 on error
 */
int unset_alias(info_t *info, char *alias_str)
{
	char *equal_sign, character;
	int result;

	equal_sign = _strchr(alias_str, '=');
	if (!equal_sign)
	return (1);
	character = *equal_sign;
	*equal_sign = 0;
	result = delete_alias(&(info->alias),
	get_alias_index(info->alias, alias_starts_with(info->alias, alias_str, -1)));
	*equal_sign = character;
	return (result);
}

/**
 * set_alias - set an alias
 * @info: Parameter struct
 * @alias_str: The string alias
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *info, char *alias_str)
{
	char *equal_sign;

	equal_sign = _strchr(alias_str, '=');
	if (!equal_sign)
	return (1);
	if (!*++equal_sign)
	return (unset_alias(info, alias_str));

	unset_alias(info, alias_str);
	return (add_alias_end(&(info->alias), alias_str, 0) == NULL);
}

/**
 * print_alias - print an alias
 * @alias_node: The alias node
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *alias_node)
{
	char *equal_sign_position = NULL, *current_character = NULL;

	if (alias_node)
	{
	equal_sign_position = _strchr(alias_node->str, '=');
	for (current_character = alias_node->str; current_character <= equal_sign_position; current_character++)
	_putchar(*current_character);
	_putchar('\'');
	_puts(equal_sign_position + 1);
	_puts("'\n");
	return (0);
	}
	return (1);
}

/**
 * _myalias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myalias(info_t *info)
{
	int i = 0;
	char *equal_sign_position = NULL;
	list_t *alias_node = NULL;

	if (info->argc == 1)
	{
	alias_node = info->alias;
	while (alias_node)
	{
	print_alias(alias_node);
	alias_node = alias_node->next;
	}
	return (0);
	}
	for (i = 1; info->argv[i]; i++)
	{
	equal_sign_position = _strchr(info->argv[i], '=');
	if (equal_sign_position)
	set_alias(info, info->argv[i]);
	else
	print_alias(alias_starts_with(info->alias, info->argv[i], '='));
	}

	return (0);
}
