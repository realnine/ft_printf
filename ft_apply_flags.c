/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:01:06 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/16 15:01:10 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_apply_prec(t_flags *flags, char *str)
{
	int	num;

	num = flags->dot_val - ft_strlen(str);
	if (num < 0 && flags->type == 's')
	{
		if (!(str = ft_cut_str(str, flags)))
			return (NULL);
	}
	else if (flags->type != 's')
	{
		if (str[0] == '-')
			num++;
		if (num > 0)
		{
			if (!(str = ft_put_zero_prec(str, flags, num)))
				return (NULL);
		}
		else if (str[0] == '0' && flags->dot_val == 0)
			str[0] = '\0';
	}
	return (str);
}

char	*ft_apply_width(t_flags *flags, char *str)
{
	int	num;

	num = flags->width - ft_strlen(str);
	if (flags->type == 'c' && *str == '\0')
		num--;
	if (num > 0)
	{
		if (flags->zero > 0 && ft_strlen(str) > 0)
		{
			if (ft_is_nbr_type(flags->type) || flags->type == '%')
			{
				if (!(str = ft_put_zero_width(str, flags, num)))
					return (NULL);
			}
		}
		else
		{
			if (!(str = ft_put_space(str, flags, num)))
				return (NULL);
		}
	}
	return (str);
}

void	ft_crash_flags(t_flags *flags)
{
	if (flags->zero > 0)
	{
		if (flags->minus > 0 || flags->width < 0)
			flags->zero = 0;
		if (flags->dot > 0 && flags->dot_val >= 0 && flags->type != '%')
			flags->zero = 0;
	}
}

char	*ft_apply_flags(t_flags *flags)
{
	char	*str;

	str = flags->ap_str;
	//if (!str)
	//	str = ft_strdup("(null)");
	ft_crash_flags(flags);
	if (flags->dot > 0 && flags->dot_val >= 0 && flags->type != '%')
		str = ft_apply_prec(flags, str);
	if (flags->type == 'p')
		str = ft_insert_0x(flags, str);
	if (flags->width != 0)
	{
		if (flags->width < 0)
		{
			flags->width *= -1;
			flags->minus = 1;
		}
		str = ft_apply_width(flags, str);
	}
	return (str);
}
