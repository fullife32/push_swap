# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 14:20:42 by eassouli          #+#    #+#              #
#    Updated: 2021/10/20 17:55:36 by eassouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

MKDIR	=	/bin/mkdir -p

CC	=	/usr/bin/clang

MAKE	=	/usr/bin/make -C

RM	=	/bin/rm -rf

INCLUDE	=	-I includes/.

PATH_S	=	srcs/

PATH_B	=	build/

# Main functions
SRCS	+=	main/main.c

# Initial check functions
SRCS	+=	check/initial_check.c \
			check/check_args.c \
			check/double_num.c

# First Sort functions
SRCS	+=	first_sort/first_sort.c \
			first_sort/create_tabs.c \
			first_sort/insertion_sort.c

# Init Stack functions
SRCS	+=	init_stack/init_stack.c \
			init_stack/create_stack.c \
			init_stack/target_stack.c

# Moves functions
SRCS	+=	moves/swap.c \
			moves/push.c \
			moves/rotate.c \
			moves/reverse_rotate.c

# Free functions
SRCS	+=	free/free_push_swap.c

# Error functions
SRCS	+=	error/error.c

# Utils functions
SRCS	+=	utils/ft_atol.c \
			utils/ft_lstadd_back.c \
			utils/ft_lstclear.c \
			utils/ft_lstdelone.c \
			utils/ft_lstlast.c \
			utils/ft_lstnew.c \
			utils/ft_memcpy.c \
			utils/ft_memset.c

OBJS	=	$(addprefix $(PATH_B), $(SRCS:.c=.o))

CFLAGS	=	-g -Wall -Wextra -Werror $(INCLUDE)

all:	$(PATH_B) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

PATH_DIR	=	main \
				check \
				first_sort \
				init_stack \
				moves \
				free \
				error \
				utils

$(PATH_B):
	$(MKDIR) $(PATH_B)
	for dir in $(PATH_DIR) ; do \
		$(MKDIR) $(PATH_B)$$dir ; \
	done

$(PATH_B)%.o:	$(PATH_S)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(RM) $(PATH_B)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re