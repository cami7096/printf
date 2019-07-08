/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 11:28:45 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/27 17:36:56 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_words(char *s, const char *str)
{
	int nbr;
	int i;

	i = 0;
	nbr = 0;
	while (s[i] && ft_separator(s[i], str))
		i++;
	if (s[i] && !ft_separator(s[i], str))
		nbr = 1;
	while (s[i])
	{
		if (!ft_separator(s[i], str) && ft_separator(s[i - 1], str))
			nbr++;
		i++;
	}
	return (nbr);
}
