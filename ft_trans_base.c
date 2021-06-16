/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trans_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 14:27:18 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/16 14:28:57 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_cat_char(char c, char *str)
{
	char	*tmp;
	int		str_len;

	if (!str)
		return (NULL);
	tmp = str;
	str_len = ft_strlen(str);
	if (!(str = calloc(str_len + 2, sizeof(char))))
		return (NULL);
	ft_strcpy(str, tmp);
	free(tmp);
	str[str_len] = c;
	return (str);
}

static char	*ft_div_num(unsigned long long nbr, char *base, int b_len)
{
	char *str;

	if (!nbr)
		return (ft_strdup(""));
	str = ft_div_num(nbr / b_len, base, b_len);
	str = ft_cat_char(base[nbr % b_len], str);
	return (str);
}

static int	ft_get_len(char *base)
{
	int chk[256];
	int i;
	int b_len;

	i = 0;
	while (i < 256)
		chk[i++] = 0;
	b_len = 0;
	while (base[b_len])
	{
		if (chk[(int)base[b_len]] || base[b_len] == '+' || base[b_len] == '-')
			return (0);
		chk[(int)base[b_len++]] = 1;
	}
	return (b_len);
}

char		*ft_hexa_base(unsigned long long nbr, char c)
{
	int		b_len;
	char	*str;
	char	*base;

	if (c == 'x' || c == 'p')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	b_len = ft_get_len(base);
	if (!b_len || b_len == 0 || b_len == 1)
		return (NULL);
	str = ft_div_num(nbr / b_len, base, b_len);
	if (!(str = ft_cat_char(base[nbr % b_len], str)))
		return (NULL);
	return (str);
}
