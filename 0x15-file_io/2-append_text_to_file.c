#include "main.h"

/**
 * append_text_to_file - a function that appends text.
 *
 * @filename: file to add text to
 * @text_content: text content to add to file
 *
 * Return: 1 on success, -1 on a failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, _written, len = 0;

	if (filename == NULL)
		return (-1);

	if (text_content != NULL)
	{
		for (len = 0; text_content[len];)
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	_written = write(fd, text_content, len);

	if (fd == -1 || _written == -1)
		return (-1);

	close(fd);

	return (1);
}
