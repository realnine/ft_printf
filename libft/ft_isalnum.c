/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 13:23:27 by jinglee           #+#    #+#             */
/*   Updated: 2021/02/08 16:01:18 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// c가 알파벳이거나 숫자일 때
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
