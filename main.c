/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:39:36 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/07 23:31:52 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
	int number = 10;
	char c = 'A';
	char str[] = "Camilla";
	int nbr = 904;
	
	printf("ft_printf                  printf\n");
	ft_printf("%d", number);
	printf("                  	   %d\n", number);
	ft_printf("%c", c);
	printf("                  	   %c\n", c);
	ft_printf("%p", str);
	printf("                  	   %p\n", str);
	ft_printf("%s", str);
	printf("                    %s\n", str);
	ft_printf("%o", nbr);
	printf("			   %o\n", nbr);
}
