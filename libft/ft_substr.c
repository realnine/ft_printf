/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 17:20:57 by jinglee           #+#    #+#             */
/*   Updated: 2021/02/09 15:58:54 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *src, unsigned int start, size_t len)
{
	char			*dst;
	unsigned int	src_siz;
	int				i;

	dst = malloc(len + 1);
	if (!dst || !src)
		return (NULL);
	src_siz = ft_strlen(src);
	i = 0;
	while (src[start] && len-- && start < src_siz)
		dst[i++] = src[start++];
	dst[i] = '\0';
	return (dst);
}
