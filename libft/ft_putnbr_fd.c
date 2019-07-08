/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:31:52 by cbernabo          #+#    #+#             */
/*   Updated: 2019/02/23 17:09:53 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	n1;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		n1 = (unsigned int)(n * -1);
	}
	else
		n1 = (unsigned int)n;
	if (n1 >= 10)
		ft_putnbr_fd(n1 / 10, fd);
	ft_putchar_fd((char)(n1 % 10 + '0'), fd);
}
