#include "main.h"

/**
 * create_file - creates a file.
 * @filename: The name of the file to create.
 * @text_content: A NULL-terminated string to write to the file.
 *
 * Return: 1 on success, -1 on fialure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd, write_result, close_result = 0;

	if (filename == NULL)
		return (-1);
	
	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		while (text_content[close_result] != '\0')
			close_result++;

		write_result = write(fd, text_content, close_result);
		if (write_result == -1)
			return (-1);
	}

	close(fd);
	return (1);
}
