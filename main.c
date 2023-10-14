#include "hotrace.h"
#include <fcntl.h>
#include <stdio.h>
int	main(void)
{
	int		fd;
	int		output_len;
	char	*output;
	int result;

	fd = open("tests/testfile.htr", O_RDONLY);
	fd = 1;
	printf("fd: %i\n", fd);
	if (fd == -1)
	{
		printf("open failed\n");
		return (1);
	}
	result = 0;
	output = read_out(fd, &result);
	while (output && result == NOT_END_FILE)
	{
		output = read_out(fd, &result);
		// check_result
		// parse_output
		printf("%s", output);
	}
	printf("%s\n", output);
	if (!output)
	{
		printf("read_out failed\n");
		return ((void) close(fd), 2);
	}
	printf("--------------------------------------------------\n");
	output_len = printf("output:\n%s\n", output);
	printf("--------------------------------------------------\n");
	printf("output_len: %i\n", output_len);
	free(output);
	(void) close(fd);
}

