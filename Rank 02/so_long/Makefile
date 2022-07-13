# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 15:58:18 by kwolee            #+#    #+#              #
#    Updated: 2022/07/12 14:32:27 by kwolee           ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		:=	so_long

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror

SRCS		:=	so_long.c \
				map.c \
				utils.c \
				image.c \
				key.c \
				get_next_line.c \
				get_next_line_utils.c \

OBJS		:=	$(SRCS:.c=.o)

LIBFT		:=	-L./libft -lft

MLXL		:=	-L./mlx -lmlx

FR			:=	-framework OpenGL -framework AppKit

ARCH		:=	arch -x86_64

%.o			:	%.c Makefile
			$(ARCH) $(CC) $(CFLAGS) -c $< -o $@

all			:	$(NAME)

$(NAME)		:	$(OBJS)
			$(ARCH) make all -C ./mlx
			$(ARCH) make all -C ./libft
			$(ARCH) $(CC) $(CFLAGS) $(LIBFT) $(MLXL) $(FR) $(OBJS) -o $(NAME)

clean		:
		rm -f $(OBJS)
		rm -f ./mlx/*.o
		make clean -C ./libft

fclean		:	clean
		make clean -C ./mlx
		make fclean -C ./libft
		rm -f $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re bonus