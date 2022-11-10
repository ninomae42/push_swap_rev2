/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:45:47 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 21:08:56 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_cont	*init_push_swap(int argc, char **argv)
{
	t_cont	*controller;

	controller = (t_cont *)malloc_or_exit(sizeof(t_cont));
	controller->argc = argc;
	controller->argv = argv;
	controller->stack_a = dstack_init();
	controller->stack_b = dstack_init();
	controller->ops = ops_init();
	controller->original_array = (int *)malloc_or_exit(
			sizeof(int) * (argc - 1));
	controller->sorted_array = (int *)malloc_or_exit(sizeof(int) * (argc - 1));
	controller->cm = init_cost_manager();
	return (controller);
}

void	receive_cmdline_argument(t_cont *controller)
{
	size_t	i;
	char	**argv;
	int		ret;

	i = 1;
	argv = controller->argv;
	while (argv[i] != NULL)
	{
		errno = 0;
		ret = ft_atoi_int(argv[i]);
		if (errno != 0)
		{
			ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		controller->original_array[i - 1] = ret;
		controller->sorted_array[i - 1] = ret;
		i++;
	}
}

void	sort_and_check_duplication(t_cont *controller)
{
	int		*buf;
	int		*array;
	size_t	size;

	size = controller->argc - 1;
	buf = (int *)malloc(sizeof(int) * size);
	array = controller->sorted_array;
	merge_sort(array, buf, 0, size);
	if (is_duplicate_exist(array, size))
	{
		ft_putstr_fd(ERROR_MSG, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	free(buf);
}

void	compress(t_cont *controller)
{
	size_t	size;
	size_t	i;
	size_t	tmp;

	i = 0;
	size = controller->argc - 1;
	tmp = 0;
	while (i < size)
	{
		tmp = find_index_of_key(controller->sorted_array, size,
				controller->original_array[i]);
		dstack_push_back(controller->stack_a, tmp);
		i++;
	}
}

t_cm	*init_cost_manager(void)
{
	t_cost_manager	*cm;

	cm = (t_cost_manager *)malloc_or_exit(sizeof(t_cost_manager));
	cm->cost_a = 0;
	cm->cost_b = 0;
	cm->is_reverse_a = false;
	cm->is_reverse_b = false;
	cm->total_cost = 0;
	cm->min_cost = 0;
	cm->min_cost_number = 0;
	cm->rotate_cnt_both = 0;
	cm->rotate_cnt_a = 0;
	cm->rotate_cnt_b = 0;
	cm->rotate_is_reverse_a = false;
	cm->rotate_is_reverse_b = false;
	return (cm);
}
