#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	char	*tmp;
	int		i;

	i = INT_MAX;
	tmp = (char *) malloc(i + 1);
	if (!tmp)
		printf("failed");
	free(tmp);
}
