NAME := push_swap

SRCS_DIR := ./srcs
OBJS_DIR := ./obj
SRCS := main.c \
		ft_atoi.c \
		ft_atoi_int.c \
		ft_putstr_fd.c \
		args_utils.c \
		utils.c \
		data_stack.c \
		data_stack2.c \
		ops_stack.c \
		ops_stack2.c \
		ops_swap.c \
		ops_push.c \
		ops_rotate.c \
		ops_rev_rotate.c \

OBJS := $(SRCS:.c=.o)
SRCS := $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS := $(addprefix $(OBJS_DIR)/, $(OBJS))

INC_DIR := ./includes
INCLUDES := $(addprefix -I, $(INC_DIR))

CC := cc
CFLAGS := -Wall -Wextra -Werror -fsanitize=address -g -fno-omit-frame-pointer
RM := rm -rf

.PHONY: all
all: $(NAME)

$(OBJS_DIR)/%o: $(SRCS_DIR)/%c
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

.PHONY: clean
clean:
	$(RM) $(OBJS_DIR)

.PHONY: fclean
fclean: clean
	$(RM) $(NAME)

.PHONY: re
re: fclean all

.PHONY: norm
norm:
	-@norminette includes/
	-@norminette srcs/
