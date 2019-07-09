/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 20:45:12 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/08 20:53:08 by cbernabo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int main(void)
{
	int nbr = 10;

	printf("Lengh HH: %hhd\n", (signed char) nbr);
	printf("Lengh H: %hd\n", (short int) nbr);
	printf("Lengh L: %ld\n", (long int) nbr);
	printf("Lengh LL; %lld\n", (long long int) nbr * 100000000000);
}	
