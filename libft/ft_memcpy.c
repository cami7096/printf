/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 20:24:48 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/23 17:51:03 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*restrict dst, const void *restrict src, size_t n)
{
	size_t				i;
	unsigned char		*pointerdst;
	const unsigned char *pointersrc;

	pointerdst = (unsigned char *)dst;
	pointersrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		pointerdst[i] = pointersrc[i];
		i++;
	}
	return (dst);
}
