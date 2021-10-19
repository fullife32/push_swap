# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/29 14:20:42 by eassouli          #+#    #+#              #
#    Updated: 2021/10/19 13:49:56 by eassouli         ###   ########.fr        #
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
SRCS	+=	initial_check/initial_check.c \
			initial_check/check_list.c

# First Sort functions
SRCS	+=	first_sort/first_sort.c \
			first_sort/create_tabs.c \
			first_sort/insertion_sort.c

# Free functions
SRCS	+=	free/free_push_swap.c

# Error functions
SRCS	+=	error/error.c

# Utils functions
SRCS	+=	utils/ft_atol.c \
			utils/ft_memcpy.c \
			utils/ft_memset.c

OBJS	=	$(addprefix $(PATH_B), $(SRCS:.c=.o))

CFLAGS	=	-g -Wall -Wextra -Werror $(INCLUDE)

all:	$(PATH_B) $(NAME)

$(NAME):	$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)

PATH_DIR	=	main \
				first_sort \
				initial_check \
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