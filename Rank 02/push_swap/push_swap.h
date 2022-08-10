/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 14:11:36 by kwolee            #+#    #+#             */
/*   Updated: 2022/08/10 15:18:54 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_number
{
	struct s_number	*prev;
	int				content;
	struct s_number	*next;
}t_number;

typedef struct s_info
{
	int				*array;
	int				size_a;
	struct s_number	*top_a;
	struct s_number	*bottom_a;
	int				size_b;
	struct s_number	*top_b;
	struct s_number	*bottom_b;
}t_info;

void		puterr(int type);
t_number	*init_stack(void);

int			count_split_str(char **split_str);
void		free_str(char **array);
int			ft_atoll(const char *str);
void		str_to_array(int *array, int *arr_index, char **str);

int			count_str(int argc, char *argv[]);
int			*argv_to_array(int argc, char *argv[], int size);
void		array_to_stack(t_info *info, int *array, int size);
void		check_array_sort(int *array, int size, int index);

void		ra(t_info *info);
void		rb(t_info *info);
void		rr(t_info *info);

void		rra(t_info *info);
void		rrb(t_info *info);
void		rrr(t_info *info);

void		sa(t_info *info);
void		sb(t_info *info);
void		ss(t_info *info);
void		pa(t_info *info);
void		pb(t_info *info);

void		sort_begin(t_info *info);

void		sort_over_three_end(t_info *info);
void		devide_three_layer(t_info *info, int pivot1, int pivot2);
void		select_pivot(t_info *info);
void		cal_min_rotate(t_info *info, int *a, int *b);

int			set_a_location(int num, t_info *info);
void		rotate_all(t_info *info, int *a, int *b);
void		rotate_a(t_info *info, int a);
void		rotate_b(t_info *info, int b);

int			get_stack_min(t_number *stack);
int			set_a_location_min(t_info *info);
int			get_stack_max(t_number *stack);
int			set_a_location_max(t_info *info);
int			set_a_location_mid(int num, t_info *info);

#endif