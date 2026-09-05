#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int	main(void)
{
	char buffer[BUFFER_SIZE + 1];
	ssize_t bytes_read;

	bytes_read = read(0, buffer, BUFFER_SIZE);
	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		printf("result: %s", buffer);
	}

	bytes_read = read(0, buffer, BUFFER_SIZE);

	if (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		printf("second result: %s\n", buffer);
	}

	return (0);
}