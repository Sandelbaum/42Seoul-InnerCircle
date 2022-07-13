/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 20:56:02 by kwolee            #+#    #+#             */
/*   Updated: 2022/07/12 22:32:30 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include "./get_next_line.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3

# define X_EVENT_KEY_EXIT		17
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2

typedef struct s_img {
	void	*cha;
	void	*exit;
	void	*gnd;
	void	*key;
	void	*key2;
	void	*wall;
}t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		w;
	int		h;
	char	*str_line;
	int		all_col;
	int		col_cnt;
	int		walk_cnt;
}t_game;

char	*ft_strdup_with_no_nl(char *s);
int		ft_strlcpy_with_no_nl(char *dst, char *src, int len);
char	*ft_strjoin_with_no_nl(char *s1, char *s2);

t_img	img_init(void *mlx);
void	setting_img(t_game *game);

void	map_read(char *filename, t_game *game);
void	map_check(t_game *game);

int		clear_game(t_game *game);
void	press_w(t_game *g);
void	press_a(t_game *g);
void	press_s(t_game *g);
void	press_d(t_game *g);

void	print_err(char *message);
void	game_init(t_game *g, char *map);
int		exit_game(t_game *game);
int		press_key(int key_code, t_game *game);

#endif