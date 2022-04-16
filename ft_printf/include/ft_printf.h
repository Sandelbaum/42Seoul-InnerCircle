/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwolee <kwolee@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:42:30 by kwolee            #+#    #+#             */
/*   Updated: 2022/04/16 00:44:56 by kwolee           ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *format, ...);
int		print_char(int c);
int		print_str(char *str);
int		print_dec(int n);
int		print_uint(unsigned int n);
int		print_hexdec(unsigned int num, const char format);
int		print_ptr(unsigned long long ptr);
void	put_str(char *str);

#endif
