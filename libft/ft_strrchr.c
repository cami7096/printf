/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:32:06 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/14 21:40:09 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*l;

	l = (0);
	while (*s)
	{
		if (*s == c)
			l = ((char*)s);
		s++;
	}
	if (l)
		return (l);
	if (c == '\0')
		return ((char*)s);
	else
		return (NULL);
}
