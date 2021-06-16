/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:29:11 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/16 14:30:26 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->width = 0;
	flags->dot = 0;
	flags->dot_val = 0;
	flags->star = 0;
	flags->minus = 0;
	flags->type = '\0';
	flags->ap_str = "init";
	return ;
}

int		ft_is_specifier(int c)
{
	return (ft_strchr("0123456789-.*csdiupxX%", c) ? 1 : 0);
}

int		ft_is_type(int c)
{
	return (ft_strchr("csdiupxX%", c) ? 1 : 0);
}

int		ft_is_flag(int c)
{
	return (ft_strchr("0-.*", c) ? 1 : 0);
}

int		ft_is_nbr_type(char c)
{
	if (c == 's' || c == 'c' || c == '%')
		return (0);
	return (1);
}
