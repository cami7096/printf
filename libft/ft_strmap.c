/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 17:33:31 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/21 17:55:46 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*s1;
	char	*s2;
	char	*res;
	int		i;

	if (!s || !(res = ft_memalloc((size_t)ft_strlen((char *)s) + 1)))
		return (NULL);
	s1 = (char *)s;
	s2 = res;
	i = 0;
	while (s1[i])
	{
		s2[i] = f(s1[i]);
		i++;
	}
	return (res);
}
