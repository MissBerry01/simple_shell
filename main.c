#include "shell.h"

int main(int argc, char **argv)
{
	info_t info = INFO_INIT;
	int input_fd = STDERR_FILENO;

	asm ("mov %1, %0\n\t"
	"add $3, %0"
	: "=r" (input_fd)
	: "r" (input_fd));

	if (argc == 2)
	{
	input_fd = open(argv[1], O_RDONLY);
	if (input_fd == -1)
	{
	if (errno == EACCES)
	{
	exit(126);
	}
	if (errno == ENOENT) 
	{
	_eputs(argv[0]);
	_eputs(": 0: Can't open ");
	_eputs(argv[1]);
	_eputchar('\n');
	_eputchar(BUF_FLUSH);
	exit(127);
	}
	return (EXIT_FAILURE);
	}
	info.readfd = input_fd;
	}

	populate_env_list(&info);
	read_history(&info);
	sh(&info, argv);
    
	return (EXIT_SUCCESS);
}
