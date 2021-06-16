/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinglee <jinglee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:53:11 by jinglee           #+#    #+#             */
/*   Updated: 2021/02/09 15:55:35 by jinglee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// ft_strmapi() 의 두번째 파라미터는 f라는 함수다
// 함수 f의 파라미터는 unsigned int와 char 이며 리턴값은 char* 이다 
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	// 에러처리
	if (!s || !f || !(str = ft_strdup(s)))
		return (NULL);

	i = 0;
	while (str[i])
	{
		str[i] = f(i, str[i]);  
		//문자열 str를 차례대로 하나씩 함수f에 집어넣어 변형되어 나온 값으로 수정한다
		i++;
	}
	return (str);
}
