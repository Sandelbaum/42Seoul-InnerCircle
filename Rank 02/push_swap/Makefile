# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/05 15:02:47 by kwolee            #+#    #+#              #
#    Updated: 2022/08/10 15:10:54 by kwolee           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		:=	push_swap

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

SRCS		:=	push_swap.c \
				argument.c \
				argument_utils.c \
				rr_op.c \
				rrr_op.c \
				s_p_op.c \
				sort_begin.c \
				sort_begin_utils.c \
				rotate_al.c \
				rotate_al_utils.c \

OBJS		:=	$(SRCS:.c=.o)

LIBFT		:=	-L./libft -lft

INCS		:=	-I.

RM			:=	rm -f

%.o			:	%.c Makefile
			$(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			make all -C ./libft
			$(CC) $(CFLAGS) $(LIBFT) $(OBJS) -o $(NAME)

clean		:
		$(RM) $(OBJS)
		make clean -C ./libft

fclean		:	clean
		make fclean -C ./libft
		$(RM) $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re