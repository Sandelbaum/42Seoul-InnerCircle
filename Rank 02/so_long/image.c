/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 19:24:47 by kwolee            #+#    #+#             */
/*   Updated: 2022/07/12 22:31:58 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(void *mlx)
{
	t_img	rt;
	int		w;
	int		h;

	rt.gnd = mlx_xpm_file_to_image(mlx, "./images/grass.xpm", &w, &h);
	rt.wall = mlx_xpm_file_to_image(mlx, "./images/tree.xpm", &w, &h);
	rt.cha = mlx_xpm_file_to_image(mlx, "./images/arthur.xpm", &w, &h);
	rt.exit = mlx_xpm_file_to_image(mlx, "./images/excalibur.xpm", &w, &h);
	rt.key = mlx_xpm_file_to_image(mlx, "./images/merlin.xpm", &w, &h);
	rt.key2 = mlx_xpm_file_to_image(mlx, "./images/staff.xpm", &w, &h);
	return (rt);
}

static void	put_img(t_game *g, int w, int h)
{
	if (g->str_line[h * g->w + w] == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.wall, w * 32, h * 32);
	else if (g->str_line[h * g->w + w] == 'C')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.gnd, w * 32, h * 32);
		mlx_put_image_to_window(g->mlx, g->win, g->img.exit, w * 32, h * 32);
	}
	else if (g->str_line[h * g->w + w] == 'P')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.gnd, w * 32, h * 32);
		mlx_put_image_to_window(g->mlx, g->win, g->img.cha, w * 32, h * 32);
	}
	else if (g->str_line[h * g->w + w] == 'E' && g->all_col == g->col_cnt)
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.gnd, w * 32, h * 32);
		mlx_put_image_to_window(g->mlx, g->win, g->img.key, w * 32, h * 32);
	}
	else if (g->str_line[h * g->w + w] == 'E')
	{
		mlx_put_image_to_window(g->mlx, g->win, g->img.gnd, w * 32, h * 32);
		mlx_put_image_to_window(g->mlx, g->win, g->img.key2, w * 32, h * 32);
	}
	else
		mlx_put_image_to_window(g->mlx, g->win, g->img.gnd, w * 32, h * 32);
}

void	setting_img(t_game *game)
{
	int		h;
	int		w;

	h = 0;
	while (h < game->h)
	{
		w = 0;
		while (w < game->w)
		{
			put_img(game, w, h);
			w++;
		}
		h++;
	}
}
