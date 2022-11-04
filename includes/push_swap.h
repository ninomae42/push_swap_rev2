#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <errno.h>
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// ----- Types -----
// data stack
typedef struct s_data_node
{
	int					num;
	struct s_data_node	*next;
	struct s_data_node	*prev;
}	t_data_node;

typedef t_data_node		t_dnode;

typedef struct s_data_stack
{
	t_dnode	*nil;
	size_t	size;
}	t_data_stack;

typedef t_data_stack	t_dstack;

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

#endif
