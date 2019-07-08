/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:29:57 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/27 10:46:14 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pntr;
	size_t			n;

	n = 0;
	pntr = (unsigned char *)b;
	while (len-- > n)
	{
		*(pntr++) = (unsigned char)c;
	}
	return (b);
}
