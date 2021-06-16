/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:54:15 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/16 01:00:37 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct	s_flags
{
	int			zero;
	int			width;
	int			dot;
	int			dot_val;
	int			star;
	int			minus;
	char		type;
	char		*ap_str;
}				t_flags;

int				ft_printf(const char *format, ...);
char			*ft_check_flags(t_flags *flags, char *format, va_list ap);
int				ft_final_putstr(t_flags *flags, char *str);
char			*ft_hexa_base(unsigned long long nbr, char c);
char			*ft_itoa_unint(unsigned int n);
char			*ft_apply_flags(t_flags *flags);
void			ft_init_flags(t_flags *flags);
char			*ft_put_space(char *str, t_flags *flags, int empty_num);
char			*ft_put_zero_prec(char *str, t_flags *flags, int zero_num);
char			*ft_put_zero_width(char *str, t_flags *flags, int zero_num);
char			*ft_cut_str(char *str, t_flags *flags);
char			*ft_insert_0x(t_flags *flags, char *str);
void			ft_putchar(char c);
size_t			ft_strcat(char *dst, const char *src);
char			*ft_strcpy(char *dst, const char *src);
void			ft_putstr(char *s);
int				ft_is_specifier(int c);
int				ft_is_type(int c);
int				ft_is_flag(int c);
int				ft_is_nbr_type(char c);

#endif
