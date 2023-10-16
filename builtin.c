#include "shell.h"

/**
 * _myexit - exits the shell
 * @info: Structure containing potential arguments.
 * Return: exits with a given exit status (0) if info->argv[0] != "exit"
 */
int _myexit(info_t *info)
{
	int exit_status;

	if (info->argv[1])
	{
	exit_status = _erratoi(info->argv[1]);
	if (exit_status == -1)
	{
	info->status = 2;
	print_error(info, "Illegal exit status: ");
	_eputs(info->argv[1]);
	_eputchar('\n');
	return (1);
	}
	info->err_num = exit_status;
	}
	else
	{
	info->err_num = -1;
	}
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @info: contains potential arguments.
 * Return: 0 on success, 1 on failure
 */
int _mycd(info_t *info)
{
	char *target_directory, current_directory[1024];
	int chdir_result;

	if (!getcwd(current_directory, sizeof(current_directory)))
	{
	perror("getcwd");
	return (1);
	}

	if (!info->argv[1])
	{
	target_directory = _getenv(info, "HOME=");
	if (!target_directory) 
	{
	target_directory = _getenv(info, "PWD=");
        }
	}
	else if (_strcmp(info->argv[1], "-") == 0) 
	{
	target_directory = _getenv(info, "OLDPWD=");
	}
	else
	{
	target_directory = info->argv[1];
	}

	chdir_result = chdir(target_directory);
	if (chdir_result == -1)
	{
	perror("chdir");
	return (1);
	}

	_setenv(info, "OLDPWD", _getenv(info, "PWD="));
	_setenv(info, "PWD", getcwd(current_directory, sizeof(current_directory)));
	return (0);
}

/**
 * _myhelp - prints help message
 * @info: Structure containing potential arguments.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	_puts("This is a simple shell. It supports basic commands.\n");
	return (0);
}
