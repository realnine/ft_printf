/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:39:45 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/17 18:56:33 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_args(va_list ap, t_flags *flags)
{
	if (flags->type == 'c')
	{
		if (!(flags->ap_str = ft_calloc(2, sizeof(char))))
			return (-1);
		*flags->ap_str = va_arg(ap, int);
	}
	else if (flags->type == 's')
		flags->ap_str = ft_strdup(va_arg(ap, char *));
	else if (flags->type == 'p')
		flags->ap_str = ft_hexa_base(va_arg(ap, unsigned long long), 'p');
	else if (flags->type == 'd' || flags->type == 'i')
		flags->ap_str = ft_itoa(va_arg(ap, int));
	else if (flags->type == 'u')
		flags->ap_str = ft_itoa_unint(va_arg(ap, unsigned int));
	else if (flags->type == 'x')
		flags->ap_str = ft_hexa_base(va_arg(ap, unsigned int), 'x');
	else if (flags->type == 'X')
		flags->ap_str = ft_hexa_base(va_arg(ap, unsigned int), 'X');
	else if (flags->type == '%')
		flags->ap_str = ft_strdup("%");
	else
		flags->ap_str = ft_strdup("");
	if (flags->ap_str == NULL)
		return (-1);
	return (1);
}

char	*ft_percent_check(t_flags *flags, va_list ap, char *format)
{
	format++;
	ft_init_flags(flags);
	format = ft_check_flags(flags, format, ap);
	if (ft_get_args(ap, flags) == -1)
		return (NULL);
	return (format);
}

int		ft_check_format(char *format, va_list ap)
{
	int		cnt;
	char	*str;
	t_flags	*flags;

	if (!(flags = malloc(sizeof(t_flags) * 1)))
		return (-1);
	cnt = 0;
	while (*format != '\0')
	{
		while (*format != '%' && *format != '\0')
		{
			ft_putchar(*format++);
			cnt++;
		}
		if (*format == '%')
		{
			if(!(format = ft_percent_check(flags, ap, format)))
				return (-1);
			if (!(str = ft_apply_flags(flags)))
				return (-1);
			cnt += ft_final_putstr(flags, str);
		}
	}
	free(flags);
	return (cnt);
}

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list ap;

	va_start(ap, format);
	i = ft_check_format((char *)format, ap);
	va_end(ap);
	return (i);
}
int main()
{
	ft_printf("%d\n", 42);
	ft_printf("%s\n", "42");
	ft_printf("%c\n", 'c');
	system("leaks a.out > leaks_result; cat leaks_result | grep leaked && rm -rf leaks_result");
	return (0);
}
