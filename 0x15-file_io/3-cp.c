#include "main.h"

/**
 * open_source_file - Opens the source file for reading.
 *
 * @filename: Name of the source file.
 *
 * Return: File descriptor on success, -1 on error.
 */
int open_source_file(const char *filename)
{
	int file_from = open(filename, O_RDONLY);

	if (file_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", filename);
		exit(98);
	}

	return (file_from);
}

/**
 * open_destination_file - Opens the destination file for writing.
 *
 * @filename: Name of the destination file.
 *
 * Return: File descriptor on success, -1 on error.
 */
int open_destination_file(const char *filename)
{
	int file_to = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 00664);

	if (file_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", filename);
		exit(99);
	}

	return (file_to);
}

/**
 * close_file - Closes a file descriptor.
 *
 * @fd: File descriptor to close.
 *
 * Return: 0 on success, -1 on error.
 */
int close_file(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		return (-1);
	}
	return (0);
}

/**
 * main - Copies the content of a file to another file.
 *
 * @argc: Argument count.
 * @argv: Argument vector.
 *
 * Return: 0 on success, appropriate error codes on failure.
 */
int main(int argc, char *argv[])
{
	int file_from, file_to;
	ssize_t read_len, write_len;
	char buffer[1024];

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	file_from = open_source_file(argv[1]);
	file_to = open_destination_file(argv[2]);

	while ((read_len = read(file_from, buffer, 1024)) != 0)
	{
		if (read_len == -1)
			exit(98);

		write_len = write(file_to, buffer, read_len);
		if (write_len != read_len || write_len == -1)
			exit(99);
	}

	if (close_file(file_from) == -1 || close_file(file_to) == -1)
		exit(100);

	return (0);
}
