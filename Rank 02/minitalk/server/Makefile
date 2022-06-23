# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 19:54:13 by kwolee            #+#    #+#              #
#    Updated: 2022/06/23 21:44:03 by kwolee           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		:=	server

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

SRCS		:=	server.c server_process.c

INCS		:=	-I.

OBJS		:=	$(SRCS:.c=.o)

LIBFT		:=	../libft/

LIBFT_LIB	:=	libft.a

%.o			:	%.c Makefile
			$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			make -C $(LIBFT) all
			$(CC) $(CFLAGS) -L$(LIBFT) -lft $(INCS) $(OBJS) -o $(NAME) 

clean		:
			make -C $(LIBFT) clean
			rm -f $(OBJS)

fclean		:	clean
			make -C $(LIBFT) fclean
			rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re