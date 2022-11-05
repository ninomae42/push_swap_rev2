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
	int					num;
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

// controller
typedef struct s_controller
{
	int			argc;
	char		**argv;
	t_dstack	*stack_a;
	t_dstack	*stack_b;
	t_ops		*ops;
	int			*sorted_array;
}	t_controller;

typedef t_controller		t_cont;

// ----- Functions -----

// data_stack.c
t_dstack	*dstack_init(void);
t_dnode		*dnode_new(int num);
void		dstack_push_front(t_dstack *stack, int num);
void		dstack_push_back(t_dstack *stack, int num);
void		dstack_print(t_dstack *stack);

// data_stack2.c
int			dstack_peek(t_dstack *stack);
void		dstack_erace(t_dstack *stack, t_dnode *node);
void		dstack_pop_front(t_dstack *stack);
void		dstack_clear(t_dstack *stack);
t_dstack	*dstack_copy(t_dstack *stack);

// ft_atoi.c
int			ft_atoi(const char *str);
// ft_atoi_int.c
int			ft_atoi_int(const char *str);

// args_utils.c
bool		is_argument_valid(const char *s);

// utils.c
void		*malloc_or_exit(size_t size);

// ft_putstr_fd.c
void		ft_putstr_fd(const char *s, int fd);

// ops_stack.c
t_opsnode	*opsnode_new(t_eops operation);
t_ops		*ops_init(void);
void		ops_push_back(t_ops *ops, t_eops operation);
char		*enum_ops_to_string(t_eops operation);
void		ops_print(t_ops *ops);

// ops_stack2.c
void		ops_erace(t_ops *ops, t_opsnode *node);
void		ops_clear(t_ops *ops);

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

// array.c
int			*stack_to_array(t_dstack *stack);
void		print_array(int *array, size_t size);
bool		is_duplicate_exist(int *array, size_t size);

// merge_sort.c
void		merge_sort(int *a, int *buf, size_t left, size_t right);

#endif
