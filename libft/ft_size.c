/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:37:45 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/26 19:06:23 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_size(char *s, char const *str)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (s[i] && !ft_separator(s[i], str))
	{
		size++;
		i++;
	}
	return (size);
}
