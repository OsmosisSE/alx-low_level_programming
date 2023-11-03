#include "main.h"
#include <stdio.h>
#include <stdib.h>

char *create_buffer(char *file);
void close_file(int fd);

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
	char *buffer;

	if (argc != 3 || (fd_from = open(argv[1], O_RDONLY)) == -1 ||
			(fd_to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664)) == -1)
	{
		if (argc != 3)
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		else if (fd_from == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		else
		{
			close(fd_from);
			dprintf(STDERR_FILENO, "Error: Can't write to file %s\n", argv[2]);
		}
		return (argc != 3 ? 97 : 98);
	}

	while ((_read = read(fd_from, buffer, *buffer)) > 0)
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

	if (_read == -1 || (close(fd_from) == -1) | (close(fd_to) == -1))
	{
		if (_read == -1)
			dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		else
			dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", (close(fd_from) == -1) ? fd_to : fd_from);
        return (_read == -1 ? 98 : 100);
        }

	return (0);
}

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */
char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * 1024);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * close_file - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void close_file(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
