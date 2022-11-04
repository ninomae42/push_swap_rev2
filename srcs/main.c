#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t	i;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	i = 1;
	while ((int)i < argc)
	{
		printf("%s ", argv[i]);
		i++;
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
