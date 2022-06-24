# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 20:08:37 by kwolee            #+#    #+#              #
#    Updated: 2022/06/24 14:30:34 by kwolee           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		:=	server client

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

SRCS_S		:=	server.c server_process.c

SRCS_C		:=	client.c client_send.c

SRCS_S_B	:=	server_bonus.c server_process_bonus.c

SRCS_C_B	:=	client_bonus.c client_send_bonus.c

OBJS_S		:=	$(SRCS_S:.c=.o)

OBJS_C		:=	$(SRCS_C:.c=.o)

OBJS_S_B	:=	$(SRCS_S_B:.c=.o)

OBJS_C_B	:=	$(SRCS_C_B:.c=.o)

INCS		:=	-I.

LIBFT		:=	./libft/

LIBFT_LIB	:=	libft.a

RM			:=	rm -f

ifdef WITH_BONUS
	S_OBJS = $(OBJS_S_B)
	C_OBJS = $(OBJS_C_B)
else
	S_OBJS = $(OBJS_S)
	C_OBJS = $(OBJS_C)
endif

%.o			:	%.c Makefile
			$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

all			:	$(NAME)

bonus		:	
			make WITH_BONUS=1 all

$(NAME)		:	$(S_OBJS) $(C_OBJS)
			make -C $(LIBFT) all
			$(CC) $(CFLAGS) -L$(LIBFT) -lft $(INCS) $(S_OBJS) -o server
			$(CC) $(CFLAGS) -L$(LIBFT) -lft $(INCS) $(C_OBJS) -o client

clean		:
			make -C $(LIBFT) clean
			$(RM) $(OBJS_S) $(OBJS_C) $(OBJS_S_B) $(OBJS_C_B)

fclean		:	clean
			make -C $(LIBFT) fclean
			$(RM) server
			$(RM) client


re			:	fclean all

.PHONY		:	all bonus clean fclean re