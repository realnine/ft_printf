/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_unint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:38:14 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/16 00:39:23 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_scale(unsigned int n)
{
	size_t c;

	c = 1;
	while (n / 10 != 0)
	{
		c++;
		n /= 10;
	}
	return (c);
}

static char		*ft_rec(unsigned int n, char *str, char *decimal)
{
	if (n / 10 != 0)
		str = ft_rec(n / 10, str, decimal);
	*str = decimal[n % 10];
	return (++str);
}

char			*ft_itoa_unint(unsigned int n)
{
	char	*str;
	char	*decimal;
	char	*str0;

	decimal = "0123456789";
	str = malloc(sizeof(char) * (ft_scale(n) + 1));
	if (!str)
		return (NULL);
	str0 = str;
	str = ft_rec(n, str, decimal);
	*str = '\0';
	return (str0);
}
