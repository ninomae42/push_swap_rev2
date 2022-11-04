#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t	i;
	int		ret;
	int		err;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	i = 1;
	while (argv[i] != NULL)
	{
		if (!is_argument_valid(argv[i]))
		{
			printf("error occured, with value: %s\n", argv[i]);
			exit(EXIT_FAILURE);
		}
		ret = ft_atoi_int(argv[i]);
		err = errno;
		if (err != 0)
		{
			printf("error occured, with [code: %d, value: %s]\n", err, argv[i]);
			exit(EXIT_FAILURE);
		}
		printf("%d ", ret);
		i++;
	}
	printf("\n");
	exit(EXIT_SUCCESS);
}
