/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 18:26:12 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/21 19:58:16 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s1;

	if (!s || !(s1 = ft_memalloc(len + 1)))
		return (NULL);
	s1 = ft_strncpy(s1, (char*)s + start, len);
	return (s1);
}
