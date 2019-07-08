/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 17:12:55 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/23 18:24:27 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*source;

	source = (unsigned char *)s;
	i = 0;
	while (++i <= n)
	{
		if (*(source++) == (unsigned char)c)
			return ((void *)--source);
	}
	return (NULL);
}
