# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 14:20:42 by eassouli          #+#    #+#              #
#    Updated: 2021/10/29 17:11:11 by eassouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

NAME_B	=	checker

MKDIR	=	/bin/mkdir -p

CC	=	/usr/bin/clang

MAKE	=	/usr/bin/make -C

RM	=	/bin/rm -rf

INCLUDE	=	-I includes/.

PATH_S	=	srcs/

PATHB_S	=	$(PATH_S)bonus/

PATH_B	=	build/

PATHB_B	=	$(PATH_B)bonus/

# ### Push_swap functions ### #
# Main functions #
SRCS	+=	main/main.c

# Check functions #
SRCS	+=	check/check_args.c \
			check/double_num.c

# First Sort functions #
SRCS	+=	first_sort/first_sort.c \
			first_sort/create_tabs.c \
			first_sort/insertion_sort.c

# Solve funtions #
#	Sort Stack function	#
SRCS	+=	solve/sort_stack/solve.c \
			solve/sort_stack/is_stack_sorted.c

#	Init Stack functions	#
SRCS	+=	solve/init_stack/init_stack.c \
			solve/init_stack/create_stack.c \
			solve/init_stack/target_stack.c \
			solve/init_stack/reset_pos.c

#	Little Stack functions	#
SRCS	+=	solve/little_stack/little_stack.c \
			solve/little_stack/stack_3.c \
			solve/little_stack/stack_4.c \
			solve/little_stack/stack_5.c \

#	Push To B functions	#
SRCS	+=	solve/push_to_b/push_loop_b.c \
			solve/push_to_b/sequence.c \
			solve/push_to_b/shift_sequence.c \
			solve/push_to_b/dist_to_b.c

#	Push To A functions	#
SRCS	+=	solve/push_to_a/push_loop_a.c \
			solve/push_to_a/find_pos_a.c \
			solve/push_to_a/dist_to_a.c

# Moves functions #
SRCS	+=	moves/reset_moves.c \
			moves/swap.c \
			moves/push.c \
			moves/rotate.c \
			moves/reverse_rotate.c \
			moves/find_moves.c \
			moves/exec_moves.c

# Free functions #
SRCS	+=	free/free_push_swap.c

# Error functions #
SRCS	+=	error/error.c

# Utils functions #
SRCS	+=	utils/ft_atol.c \
			utils/ft_lstadd_back.c \
			utils/ft_lstadd_front.c \
			utils/ft_lstclear.c \
			utils/ft_lstdelone.c \
			utils/ft_lstlast.c \
			utils/ft_lstnew.c \
			utils/ft_memcpy.c \
			utils/ft_memset.c

# ### Checker functions ### #
#	Main function	#
SRCS_B	+=	main/main.c

#	Check functions	#
SRCS_B	+=	check/check_args.c \
			check/double_num.c \
			check/is_stack_sorted.c

#	First Sort functions	#
SRCS_B	+=	first_sort/first_sort.c \
			first_sort/create_tabs.c \
			first_sort/insertion_sort.c

#	Init Stack functions	#
SRCS_B	+=	init_stack/init_stack.c \
			init_stack/create_stack.c \
			init_stack/target_stack.c

#	Instruction loop functions	#
SRCS_B	+=	inst_loop/inst_loop.c \
			inst_loop/check_inst.c

#	Moves functions	#
SRCS_B	+=	moves/exec_moves.c \
			moves/push.c \
			moves/reverse_rotate.c \
			moves/rotate.c \
			moves/swap.c

#	Free functions	#
SRCS_B	+=	free/free_push_swap.c

#	Error functions	#
SRCS_B	+=	error/error.c

#	Utils functions	#
SRCS_B	+=	utils/get_next_line.c \
			utils/get_next_line_utils.c \
			utils/ft_atol.c \
			utils/ft_lstadd_back.c \
			utils/ft_lstadd_front.c \
			utils/ft_lstclear.c \
			utils/ft_lstdelone.c \
			utils/ft_lstlast.c \
			utils/ft_lstnew.c \
			utils/ft_memcpy.c \
			utils/ft_memset.c

OBJS	=	$(addprefix $(PATH_B), $(SRCS:.c=.o))

OBJS_B	=	$(addprefix $(PATHB_B), $(SRCS_B:.c=.o))

CFLAGS	=	-g -Wall -Wextra -Werror $(INCLUDE)

all:	$(PATH_B) $(NAME)

bonus:	$(PATH_B) $(PATHB_B) $(NAME_B)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

$(NAME_B):	$(OBJS_B)
	$(CC) $(OBJS_B) $(CFLAGS) -o $(NAME_B)

PATH_DIR	=	main \
				check \
				first_sort \
				solve/sort_stack \
				solve/init_stack \
				solve/little_stack \
				solve/push_to_b \
				solve/push_to_a \
				moves \
				free \
				error \
				utils

PATH_DIR_B	=	main \
				check \
				first_sort \
				init_stack \
				inst_loop \
				moves \
				free \
				error \
				utils

$(PATH_B):
	$(MKDIR) $(PATH_B)
	for dir in $(PATH_DIR) ; do \
		$(MKDIR) $(PATH_B)$$dir ; \
	done

$(PATHB_B):
	$(MKDIR) $(PATHB_B)
	for dir in $(PATH_DIR_B) ; do \
		$(MKDIR) $(PATHB_B)$$dir ; \
	done

$(PATH_B)%.o:	$(PATH_S)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(PATHB_B)%.o:	$(PATHB_S)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(PATH_B) $(PATHB_B)

fclean:	clean
	$(RM) $(NAME) $(NAME_B)

re:	fclean all

.PHONY:	all clean fclean re bonus