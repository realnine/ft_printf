/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 15:00:51 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/16 15:00:55 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_config_flags(char c, t_flags *flags, va_list ap)
{
	if (c == '0')
		flags->zero = 1;
	else if (c == '-')
		flags->minus = 1;
	else if (c == '.')
		flags->dot = 1;
	else if (c == '*')
	{
		flags->star = 1;
		flags->width = va_arg(ap, int);
	}
	return ;
}

char		*ft_get_prec(t_flags *flags, char *format, va_list ap)
{
	format++;
	if (*format == '*')
	{
		flags->dot_val = va_arg(ap, int);
		format++;
	}
	else
	{
		while (ft_isdigit(*format))
		{
			flags->dot_val = flags->dot_val * 10 + *format - 48;
			format++;
		}
	}
	return (--format);
}

char		*ft_get_width(t_flags *flags, char *format)
{
	int org_width;

	org_width = 0;
	if (flags->width > 0)
		org_width = flags->width;
	while (ft_isdigit(*format))
		flags->width = flags->width * 10 + *(format++) - 48;
	if (org_width > flags->width)
		flags->width = org_width;
	return (--format);
}

char		*ft_check_flags(t_flags *flags, char *format, va_list ap)
{
	while (*format != '\0' && flags->type == '\0')
	{
		if (ft_is_flag(*format))
		{
			ft_config_flags(*format, flags, ap);
			if (*format == '.')
				format = ft_get_prec(flags, format, ap);
		}
		else if (ft_isdigit(*format))
		{
			format = ft_get_width(flags, format);
		}
		else if (ft_is_type(*format))
			flags->type = *format;
		format++;
	}
	return (format);
}
