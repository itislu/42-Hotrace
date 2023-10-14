#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int	fd;

	fd = open("tests/testfile.htr", O_RDWR);
	if (fd == -1)
	{
		printf("open failed\n");
		return (1);
	}
	while ()
	write(fd, );
	close(fd);
}
