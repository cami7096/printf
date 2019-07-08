/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/17 18:33:51 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/23 17:28:00 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*pointerdst;
	const unsigned char	*pointersrc;

	pointerdst = (unsigned char *)dst;
	pointersrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pointerdst[i] = pointersrc[i];
		if (pointerdst[i] == (unsigned char)c)
			return ((void*)(dst + i + 1));
		i++;
	}
	return (NULL);
}
