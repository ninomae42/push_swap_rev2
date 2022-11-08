#include "push_swap.h"

void	print_result(t_ops *ops)
{
	t_opsnode	*nil;
	t_opsnode	*current;

	nil = ops->nil;
	current = nil->next;
	while (current != NULL && current != nil)
	{
		ft_putstr_fd(enum_ops_to_string(current->operation), STDOUT_FILENO);
		ft_putstr_fd("\n", STDOUT_FILENO);
		current = current->next;
	}
}

int	main(int argc, char **argv)
{
	t_cont		*controller;

	if (argc < 2)
		exit(EXIT_SUCCESS);
	controller = init_push_swap(argc, argv);
	receive_cmdline_argument(controller);
	sort_and_check_duplication(controller);
	compress(controller);

	dstack_print(controller->stack_a);
	dstack_print(controller->stack_b);
	puts("");

	/* sort_lte_three(controller); */
	/* sort_lte_five(controller); */
	/* dstack_print(controller->stack_a); */
	/* puts(""); */
	/* sort_lte_100(controller, 0, controller->stack_a->size - 1); */
	sort_insertion(controller);

	/* printf("stackA"); */
	/* dstack_print(controller->stack_a); */
	/* puts(""); */
	/* printf("stackB"); */
	/* dstack_print(controller->stack_b); */
	/* puts(""); */

	/* ops_print(controller->ops); */
	/* fprintf(stderr, "Operations: %zu\n", controller->ops->size); */
	/* if (!is_stack_sorted(controller->stack_a) || controller->stack_b->size != 0) */
	/* 	exit(EXIT_FAILURE); */
	/* print_result(controller->ops); */
	exit(EXIT_SUCCESS);
}
