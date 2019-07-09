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
	char *str = "Camilla";
	int nbr = 904;
	int hexa = 345945354;
	unsigned int num = 87584;
	double num_float = 377.394273;
	long int long_int = 384724775;
	long long int long_long = 87528738572983;
	
	printf("Specifiers:\n");
	printf("ft_printf                  printf\n\n");
	ft_printf("%%%d", number);
	printf("                  	   %%%d\n", number);
	ft_printf("%c", c);
	printf("                  	   %c\n", c);
	ft_printf("%p", str);
	printf("                %p\n", str);
	ft_printf("%s", str);
	printf("                    %s\n", str);
	ft_printf("%o", nbr);
	printf("			   %o\n", nbr);
	ft_printf("%x", hexa);
	printf("		   %x\n", hexa);
	ft_printf("%X", hexa);
	printf("		   %X\n", hexa);
	ft_printf("%u", num);
	printf("			   %u\n", num);
	ft_printf("%f", num_float);
	printf("		   %f\n", num_float);
	printf("\n------------------------------------------\n\n");
	printf("Lengh:\n");
	printf("\nft_printf                  printf\n");

	printf("\nINT (hh / h / ll / l):\n\n");
	ft_printf("%hhd", (signed char)number);
	printf("		   	   %hhd\n", (signed char)number);

	ft_printf("%hd", (short int)number);
	printf("		   	   %hd\n", (short int)number);

	ft_printf("%lld", long_long);
	printf("  	   %lld\n", long_long);

	ft_printf("%ld", long_int);
	printf("		   %ld\n", long_int);

	// -------------------------------------------------

	printf("\n\nUNSIGNED INT (hh / h / ll / l):\n\n");
	ft_printf("%hhu", (unsigned char)number);
	printf("		   	   %hhu\n", (unsigned char)number);

	ft_printf("%hu", (unsigned short int)number);
	printf("		   	   %hu\n", (unsigned short int)number);

	ft_printf("%llu", (unsigned long long int)long_long);
	printf("  	   %llu\n", (unsigned long long int)long_long);

	ft_printf("%lu", (unsigned long int)long_int);
	printf("		   %lu\n", (unsigned long int)long_int);

	// -------------------------------------------------

	printf("\n\nOCTAL (hh / h / ll / l):\n\n");
	ft_printf("%hho", (unsigned char)number);
	printf("		   	   %hho\n", (unsigned char)number);

	ft_printf("%ho", (unsigned short int)number);
	printf("		   	   %ho\n", (unsigned short int)number);

	ft_printf("%llo", (unsigned long long int)long_long);
	printf("  	   %llo\n", (unsigned long long int)long_long);

	ft_printf("%lo", (unsigned long int)long_int);
	printf("		   %lo\n", (unsigned long int)long_int);
}
