/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:25:06 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/23 15:34:02 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*p;
	t_list	*k;

	p = *alst;
	while (p)
	{
		k = p;
		ft_lstdelone(&p, del);
		p = k->next;
	}
	*alst = NULL;
}
