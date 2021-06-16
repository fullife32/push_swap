# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eassouli <eassouli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/26 17:20:04 by eassouli          #+#    #+#              #
#    Updated: 2021/06/16 16:58:44 by eassouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

MKDIR	=	/bin/mkdir -p

CC	=	/usr/bin/clang

MAKE	=	/usr/bin/make -C

RM	=	/bin/rm -rf

INCLUDE	=	-I includes/. \
	-I $(LIBFT)

PATH_S	=	srcs/

PATH_B	=	build/

LIBFT	=	libft

SRCS	+=	main.c

# SRCS	+=	

OBJS	=	$(addprefix $(PATH_B), $(SRCS:.c=.o))

CFLAGS	=	 -g -Wall -Wextra -Werror $(INCLUDE)

DFLAGS	=	-Llibft -lft

all:	$(PATH_B) $(NAME)

$(NAME):	$(OBJS)
	$(MAKE) $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(DFLAGS) -o $(NAME)

$(PATH_B):
	$(MKDIR) $(PATH_B)

$(PATH_B)%.o:	$(PATH_S)%.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) $(LIBFT) clean
	$(RM) $(PATH_B)

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) $(LIBFT) fclean

re:	fclean all

.PHONY:	all clean fclean re
