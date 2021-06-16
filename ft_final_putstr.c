/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_putstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 00:09:21 by jinglee           #+#    #+#             */
/*   Updated: 2021/06/16 00:11:38 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_final_putstr(t_flags *flags, char *str)
{
	int	cnt;

	cnt = ft_strlen(str);
	if (flags->type == 'c' && *(flags->ap_str) == '\0')
	{
		if (flags->minus > 0)
		{
			ft_putchar('\0');
			ft_putstr(str);
		}
		else
		{
			ft_putstr(str);
			ft_putchar('\0');
		}
		cnt++;
	}
	else
		ft_putstr(str);
	if (&(*str) != &(*flags->ap_str))
		free(flags->ap_str);
	free(str);
	return (cnt);
}
