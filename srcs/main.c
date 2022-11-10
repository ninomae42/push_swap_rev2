/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:55:13 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 20:55:15 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cont		*controller;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	controller = init_push_swap(argc, argv);
	receive_cmdline_argument(controller);
	sort_and_check_duplication(controller);
	compress(controller);
	sort_main(controller);
	ops_print_result(controller);
	exit(EXIT_SUCCESS);
}
