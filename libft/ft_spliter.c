/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spliter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 12:18:11 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/27 18:00:59 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_spliter(char *str, const char *charset)
{
	char	**tab;
	int		i;
	int		j;
	int		index;

	if (!(tab = (char**)malloc(sizeof(char*) *
					(ft_words(str, charset) + 1))))
		return (NULL);
	i = -1;
	index = -1;
	while (str[++i])
		if (!ft_separator(str[i], charset))
		{
			if (index == -1 || ft_separator(str[i - 1], charset))
			{
				if (!(tab[++index] = (char*)malloc(sizeof(char) * (ft_size(
						str + i, charset) + 1))))
					return (NULL);
				j = 0;
			}
			tab[index][j] = str[i];
			tab[index][++j] = '\0';
		}
	tab[++index] = 0;
	return (tab);
}
