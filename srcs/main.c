#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_cont		*controller;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	controller = init_push_swap(argc, argv);
	receive_cmdline_argument(controller);
	sort_and_check_duplication(controller);

	print_array(controller->original_array, controller->argc - 1);
	puts("");
	print_array(controller->sorted_array, controller->argc - 1);
	puts("");

	/* dstack_print(controller->stack_a); */
	/* dstack_print(controller->stack_b); */
	/* puts(""); */

	/* print_array(controller->sorted_array, controller->argc - 1); */
	/* puts(""); */

	compress(controller);
	dstack_print(controller->stack_a);
	/* dstack_print(controller->stack_b); */
	puts("");

	/* sort_lte_three(controller); */
	/* sort_lte_five(controller); */
	dstack_print(controller->stack_a);
	puts("");

	ops_print(controller->ops);
	if (!is_stack_sorted(controller->stack_a) || 12 < controller->ops->size)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
