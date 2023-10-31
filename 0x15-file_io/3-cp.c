#include "main.h"

#define BUFFER_SIZE 1024

/**
* main - Copies the content of one file to another.
* @argc: The number of command-line arguments.
* @argv: An array of command-line arguments.
*
* Return: 0 on success, or an exit code (97-100) on failure.
*/
int main(int argc, char *argv[])
{
	int fd_from, fd_to;
	ssize_t _read, _written;
	char buffer[BUFFER_SIZE];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		return (97);
	}

	fd_from = open(argv[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
	if (fd_to == -1)
	{
		close(fd_from);
		dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		return (99);
	}

	while ((_read = read(fd_from, buffer, BUFFER_SIZE)) > 0)
	{
		_written = write(fd_to, buffer, _read);
		if (_written == -1) 
		{
			close(fd_from);
			close(fd_to);
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
			return (99);
		}
	}

	if (_read == -1)
	{
		close(fd_from);
		close(fd_to);
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		return (98);
	}

	if (close(fd_from) == -1 || close(fd_to) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (fd_from == -1) ? fd_to : fd_from);
		return (100);
	}
	
	return (0);
}
