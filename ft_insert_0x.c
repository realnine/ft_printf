/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_0x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:34:14 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/16 00:36:57 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*insert(t_flags *flags, char *str)
{
	char *tmp;

	tmp = str;
	if (!(str = ft_calloc(ft_strlen(str) + 3, sizeof(char))))
		return (NULL);
	str[0] = '0';
	str[1] = 'x';
	ft_strcat(str, tmp);
	free(tmp);
	return (str);
}

char	*ft_insert_0x(t_flags *flags, char *str)
{
	if (flags->zero > 0 && flags->dot_val == 0)
	{
		if (str[0] == '0' && str[1] == '0')
			str[1] = 'x';
		else
			str = insert(flags, str);
	}
	else
		str = insert(flags, str);
	return (str);
}
