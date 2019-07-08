/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 20:39:33 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/27 17:33:28 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	*str;

	if (!s || !c)
		return (NULL);
	if (!(str = ft_strnew(2)))
		return (NULL);
	str[0] = c;
	return (ft_spliter((char *)s, str));
}
