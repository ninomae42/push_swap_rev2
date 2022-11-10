/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:44:03 by tashimiz          #+#    #+#             */
/*   Updated: 2022/11/10 22:35:11 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERROR_MSG "Error\n"

// ----- Types -----

// data stack
typedef struct s_data_node
{
	size_t				num;
	struct s_data_node	*next;
	struct s_data_node	*prev;
}	t_data_node;

typedef t_data_node			t_dnode;

typedef struct s_data_stack
{
	t_dnode	*nil;
	size_t	size;
}	t_data_stack;

typedef t_data_stack		t_dstack;

// operation buffer
enum e_operations {none, sa, sb, ss, pa, pb, ra, rb, rr, rra, rrb, rrr};
typedef enum e_operations	t_eops;

typedef struct s_operation_node
{
	enum e_operations		operation;
	struct s_operation_node	*next;
	struct s_operation_node	*prev;
}	t_operation_node;

typedef t_operation_node	t_opsnode;

typedef struct s_operations
{
	t_opsnode	*nil;
	size_t		size;
}	t_operations;

typedef t_operations		t_ops;

// insertion sort cost manager
typedef struct s_cost_manager
{
	size_t	cost_a;
	size_t	cost_b;
	bool	is_reverse_a;
	bool	is_reverse_b;

	size_t	total_cost;
	size_t	min_cost;
	size_t	min_cost_number;

	size_t	rotate_cnt_both;
	size_t	rotate_cnt_a;
	size_t	rotate_cnt_b;
	bool	rotate_is_reverse_a;
	bool	rotate_is_reverse_b;
}	t_cost_manager;

typedef t_cost_manager		t_cm;

// controller
typedef struct s_controller
{
	int			argc;
	char		**argv;
	t_dstack	*stack_a;
	t_dstack	*stack_b;
	t_ops		*ops;
	int			*original_array;
	int			*sorted_array;
	t_cm		*cm;
}	t_controller;

typedef t_controller		t_cont;

// ----- Functions -----

// data_stack.c
t_dstack	*dstack_init(void);
t_dnode		*dnode_new(size_t num);
void		dstack_push_front(t_dstack *stack, size_t num);
void		dstack_push_back(t_dstack *stack, size_t num);

// data_stack2.c
size_t		dstack_peek(t_dstack *stack);
void		dstack_erace(t_dstack *stack, t_dnode *node);
void		dstack_pop_front(t_dstack *stack);
void		dstack_clear(t_dstack *stack);
t_dstack	*dstack_copy(t_dstack *stack);

// data_stack3.c
bool		dstack_find(t_dstack *stack, size_t target);

// ft_atoi.c
int			ft_atoi(const char *str);
// ft_atoi_int.c
int			ft_atoi_int(const char *str);

// args_utils.c
bool		is_argument_valid(const char *s);

// utils.c
void		*malloc_or_exit(size_t size);

// ft_putstr_fd.c
size_t		ft_strlen(const char *s);
void		ft_putchar_fd(const char c, int fd);
void		ft_putstr_fd(const char *s, int fd);
void		ft_putendl_fd(const char *s, int fd);

// ops_stack.c
t_opsnode	*opsnode_new(t_eops operation);
t_ops		*ops_init(void);
void		ops_push_back(t_ops *ops, t_eops operation);
char		*enum_ops_to_string(t_eops operation);

// ops_stack2.c
void		ops_erace(t_ops *ops, t_opsnode *node);
void		ops_clear(t_ops *ops);
void		ops_print_result(t_cont *cont);

// ops_swap.c
void		swap_a(t_dstack *stack_a, t_ops *ops);
void		swap_b(t_dstack *stack_b, t_ops *ops);
void		swap_same(t_dstack *stack_a, t_dstack *stack_b, t_ops *ops);

// ops_push.c
void		push_a(t_dstack *stack_a, t_dstack *stack_b, t_ops *ops);
void		push_b(t_dstack *stack_a, t_dstack *stack_b, t_ops *ops);

// ops_rotate.c
void		rotate_a(t_dstack *stack_a, t_ops *ops);
void		rotate_b(t_dstack *stack_b, t_ops *ops);
void		rotate_same(t_dstack *stack_a, t_dstack *stack_b, t_ops *ops);

// ops_rev_rotate.c
void		reverse_rotate_a(t_dstack *stack_a, t_ops *ops);
void		reverse_rotate_b(t_dstack *stack_b, t_ops *ops);
void		reverse_rotate_same(
				t_dstack *stack_a, t_dstack *stack_b, t_ops *ops);

// initializer.c
t_cont		*init_push_swap(int argc, char **argv);
void		receive_cmdline_argument(t_cont *controller);
void		sort_and_check_duplication(t_cont *controller);
void		compress(t_cont *controller);

// array.c
int			*stack_to_array(t_dstack *stack);
bool		is_duplicate_exist(int *array, size_t size);
size_t		find_index_of_key(int *array, size_t size, int key);

// merge_sort.c
void		merge_sort(int *a, int *buf, size_t left, size_t right);

// sort_utils.c
bool		is_stack_sorted(t_dstack *stack);
bool		is_lte_key_exist(t_dstack *stack, size_t key);

// sort_lte5.c
void		sort_lte_five(t_cont *controller);
void		sort_lte_three(t_cont *controller);

// sort_main.c
void		sort_main(t_controller *cont);

// sort_helper.c
size_t		get_max(t_dstack *stack);
size_t		get_min(t_dstack *stack);

// sort_cost.c
size_t		get_cost_from_top(t_dstack *stack, size_t value);
size_t		get_cost_from_bottom(t_dstack *stack, size_t value);

// sort_cost_calcuration.c
void		traverse_and_calculate_cost(t_cont *cont);

// sort_cost_stack_a.c
void		calculate_cost_stack_a(
				t_dstack *stack, size_t b_top, t_cm *cost_manager);

// sort_cost_stack_b.c
void		calculate_cost_stack_b(
				t_dstack *stack, size_t a_top, t_cm *cost_manager);

// sort_cost_pushback_stack_a.c
size_t		calculate_cost_pushback_stack_a(
				t_dstack *stack, size_t b_top, bool *is_reverse);

// sort_manager.c
t_cm		*init_cost_manager(void);

// sort_pushback_stack_a.c
void		push_back_from_b_to_a(t_controller *cont);
void		seichi(t_controller *cont);

// sort_rotate_push_info.c
void		rotate_push_with_cost_manager_info(
				t_cont *cont, t_cost_manager *cm);

// sort_set_rotate_push_info.c
void		set_rotate_and_push_info(t_cost_manager *cm);

#endif
