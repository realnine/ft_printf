/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:07:49 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/16 00:07:59 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_put_space(char *str, t_flags *flags, int empty_num)
{
	int		i;
	char	*tmp;

	tmp = str;
	if (!(str = ft_calloc(flags->width + 1, sizeof(char))))
		return (NULL);
	if (flags->minus == 0)
	{
		i = 0;
		while (empty_num > i)
			str[i++] = ' ';
		ft_strcat(str, tmp);
	}
	else if (flags->minus > 0)
	{
		ft_strcat(str, tmp);
		i = ft_strlen(str);
		while (empty_num--)
			str[i++] = ' ';
	}
	free(tmp);
	return (str);
}

char	*ft_put_zero_prec(char *str, t_flags *flags, int gap_num)
{
	int		i;
	int		j;
	char	*tmp;

	if (flags->dot_val > 0)
	{
		tmp = str;
		if (!(str = calloc(flags->dot_val + 2, sizeof(char))))
			return (NULL);
		i = 0;
		j = 0;
		if (tmp[0] == '-')
		{
			j = 1;
			str[i++] = '-';
		}
		while (gap_num-- > 0)
			str[i++] = '0';
		ft_strcpy(&str[i], tmp + j);
		free(tmp);
	}
	return (str);
}

char	*ft_put_zero_width(char *str, t_flags *flags, int gap_num)
{
	int		i;
	int		j;
	char	*tmp;

	if (flags->zero > 0)
	{
		tmp = str;
		if (!(str = calloc(flags->width + 1, sizeof(char))))
			return (NULL);
		i = 0;
		j = 0;
		if (tmp[i] == '-')
		{
			j = 1;
			str[i++] = '-';
		}
		while (gap_num-- > 0)
			str[i++] = '0';
		ft_strcpy(&str[i], tmp + j);
		free(tmp);
	}
	return (str);
}

char	*ft_cut_str(char *str, t_flags *flags)
{
	int		str_len;
	char	*tmp;

	str_len = ft_strlen(str);
	tmp = str;
	if (!(str = calloc(flags->dot_val + 1, sizeof(char))))
		return (NULL);
	ft_strlcpy(str, tmp, flags->dot_val + 1);
	free(tmp);
	return (str);
}
