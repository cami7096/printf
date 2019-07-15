/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernabo <cbernabo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 20:39:36 by cbernabo          #+#    #+#             */
/*   Updated: 2019/07/14 20:49:29 by cbernabo         ###   ########.fr       */
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
	float num_float = 377.394273;
	long int long_int = 384724775;
	long long int long_long = 87528738572983;
	long double double_num = 38742837482.32979982734823;

	printf("Specifiers:\n");
	printf("\nft_printf                  printf\n\n");
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

	// -------------------------------------------------

	printf("\n\nHEXADECIMAL (hh / h / ll / l):\n\n");
	ft_printf("%hhx", (unsigned char)number);
	printf("		   	   %hhx\n", (unsigned char)number);
	ft_printf("%hhX", (unsigned char)number);
	printf("		   	   %hhX\n", (unsigned char)number);

	ft_printf("%hx", (unsigned short int)number);
	printf("		  	   %hx\n", (unsigned short int)number);
	ft_printf("%hX", (unsigned short int)number);
	printf("		       	   %hX\n", (unsigned short int)number);

	ft_printf("%llx", (unsigned long long int)long_long);
	printf("  	   	   %llx\n", (unsigned long long int)long_long);
	ft_printf("%llX", (unsigned long long int)long_long);
	printf("  	   	   %llX\n", (unsigned long long int)long_long);

	ft_printf("%lx", (unsigned long int)long_int);
	printf("		   %lx\n", (unsigned long int)long_int);
	ft_printf("%lX", (unsigned long int)long_int);
	printf("		   %lX\n", (unsigned long int)long_int);

	// -------------------------------------------------

	printf("\n\nFLOAT (l / L):\n\n");
	ft_printf("%lf", (double)num_float);
	printf("		   %lf\n", (double)num_float);
	ft_printf("%Lf", (long double)double_num);
	printf("	   %Lf\n", (long double)double_num);

	printf("\n------------------------------------------\n\n");
	printf("Precision:\n");
	printf("\nft_printf                  printf\n");

	ft_printf("%.0d", 0);
	printf("                 %.0d\n", 0);
	ft_printf("%.0d", 10);
	printf("                 	   %.0d\n", 10);
	ft_printf("%.1d", 100000);
	printf("                 	   %.1d\n", 100000);
	ft_printf("%.10d", number);
	printf("                 %.10d\n", number);
	ft_printf("%.2f", num_float);
	printf("                     %.2f\n", num_float);
	ft_printf("%.8f", 9.2);
	printf("                 %.8f\n", 9.2);
	ft_printf("%.4s", str);
	printf("                       %.4s\n", str);
	ft_printf("%.15s", str);
	printf("		           %.15s\n", str);
	ft_printf("%.15u", num);
	printf("		   %.15u\n", num);
	ft_printf("%.1u", num);
	printf("		           %.1u\n", num);
	ft_printf("%.10o", nbr);
	printf("                 %.10o\n", nbr);
	ft_printf("%.1o", nbr);
	printf("                       %.1o\n", nbr);
	ft_printf("%.10x", hexa);
	printf("		   %.10x\n", hexa);
	ft_printf("%.10X", hexa);
	printf("		   %.10X\n", hexa);
	ft_printf("%.1x", hexa);
	printf("		   %.1x\n", hexa);
	ft_printf("%.1X", hexa);
	printf("		   %.1X\n", hexa);
	ft_printf("%.*d", 0, 0);
	printf("                 %.*d\n", 0, 0);
	ft_printf("%.*d", 0, 10);
	printf("                 	   %.*d\n", 0, 10);
	ft_printf("%.*d", 1, 100000);
	printf("                 	   %.*d\n", 1, 100000);
	ft_printf("%.*d", 10, number);
	printf("                 %.*d\n", 10, number);
	ft_printf("%.*f", 2, num_float);
	printf("                     %.*f\n", 2, num_float);
	ft_printf("%.*f", 8, 9.2);
	printf("                 %.*f\n", 8, 9.2);
	ft_printf("%.*s", 4, str);
	printf("                       %.*s\n", 4, str);
	ft_printf("%.*s", 15, str);
	printf("		           %.*s\n", 15, str);
	ft_printf("%.*u", 15, num);
	printf("		   %.*u\n", 15, num);
	ft_printf("%.*u", 1, num);
	printf("		           %.*u\n", 1, num);
	ft_printf("%.*o", 10, nbr);
	printf("                 %.*o\n", 10, nbr);
	ft_printf("%.*o", 1, nbr);
	printf("                       %.*o\n", 1, nbr);
	ft_printf("%.*x", 10, hexa);
	printf("		   %.*x\n", 10, hexa);
	ft_printf("%.*X", 10, hexa);
	printf("		   %.*X\n", 10, hexa);
	ft_printf("%.*x", 1, hexa);
	printf("		   %.*x\n", 1, hexa);
	ft_printf("%.*X", 1, hexa);
	printf("		   %.*X\n", 1, hexa);

	printf("\n------------------------------------------\n\n");
	printf("WIDTH:\n");
	printf("\nft_printf                  printf\n\n");
	ft_printf("|%*d|", 10, 34982);
	printf("               |%*d|\n", 10, 34982);
	ft_printf("|%*d|", 1, 34982);
	printf("                    |%*d|\n", 1, 34982);
	ft_printf("|%*o|", 10, 34982);
	printf("               |%*o|\n", 10, 34982);
	ft_printf("|%*o|", 1, 34982);
	printf("                   |%*o|\n", 1, 34982);
	ft_printf("|%*u|", 10, 34982);
	printf("               |%*u|\n", 10, 34982);
	ft_printf("|%*u|", 1, 34982);
	printf("                    |%*u|\n", 1, 34982);
	ft_printf("|%*x|", 10, hexa);
	printf("		   |%*x|\n", 10, hexa);
	ft_printf("|%*X|", 1, hexa);
	printf("		   |%*X|\n", 1, hexa);
	ft_printf("|%*f|", 15, num_float);
	printf("	   |%*f|\n", 15, num_float);
	ft_printf("|%*f|", 1, num_float);
	printf("	           |%*f|\n", 1, num_float);
	ft_printf("|%*c|", 10, c);
	printf("               |%*c|\n", 10, c);
	ft_printf("|%*p|", 10, str);
	printf("              |%*p|\n", 10, str);
	ft_printf("|%*s|", 10, str);
	printf("               |%*s|\n", 10, str);

	printf("\n------------------------------------------\n\n");
	printf("FLAGS:\n");
	printf("\nft_printf                  printf\n\n");
	ft_printf("|%###*f|", 15, (double)9);
	printf("          |%###*f|\n", 15, (double)9);
	ft_printf("|%###*x|", 15, hexa);
	printf("          |%###*x|\n", 15, hexa);
	ft_printf("|%###*X|", 15, hexa);
	printf("          |%###*X|\n", 15, hexa);
	ft_printf("|%###*o|", 15, hexa);
	printf("          |%###*o|\n", 15, hexa);
	ft_printf("|%-###*X|", 15, hexa);
	printf("          |%--###*X|\n", 15, hexa);
	ft_printf("|%-###*x|", 15, hexa);
	printf("          |%--###*x|\n", 15, hexa);
	ft_printf("|%--###*o|", 15, hexa);
	printf("          |%--###*o|\n", 15, hexa);
	ft_printf("|%--*d|", 15, 34982);
	printf("          |%---*d|\n", 15, 34982);
	ft_printf("|%--*u|", 15, 34982);
	printf("          |%---*u|\n", 15, 34982);
	ft_printf("|%--*c|", 15, 'a');
	printf("          |%---*c|\n", 15, 'a');
	ft_printf("|%--*s|", 15, str);
	printf("          |%---*s|\n", 15, str);
	ft_printf("|%--*p|", 15, &str);
	printf("          |%---*p|\n", 15, &str);
	ft_printf("|%--*p|", 15, 9.2);
	printf("          |%---*p|\n", 15, &str);
	ft_printf("|%--###*f|", 15, (double)9);
	printf("          |%--###*f|\n", 15, (double)9);
	ft_printf("|%-+-###*f|", 15, (double)-9);
	printf("          |%-+-###*f|\n", 15, (double)-9);
	ft_printf("|%+*d|", 15, 34982);
	printf("          |%+*d|\n", 15, 34982);
	ft_printf("|%-+--*d|", 15, 34982);
	printf("          |%-+---*d|\n", 15, 34982);
	ft_printf("|%+*f|", 15, (double)34982);
	printf("          |%+*f|\n", 15, (double)34982);
	ft_printf("|%-+--*f|", 15, (double)34982);
	printf("          |%-+---*f|\n", 15, (double)34982);
	ft_printf("|% *d|", 15, 34982);
	printf("          |% *d|\n", 15, 34982);
	ft_printf("|%- --*d|", 15, 34982);
	printf("          |%- ---*d|\n", 15, 34982);
	ft_printf("|% *f|", 15, (double)34982);
	printf("          |% *f|\n", 15, (double)34982);
	ft_printf("|%- --*f|", 15, (double)34982);
	printf("          |%- ---*f|\n", 15, (double)34982);
	ft_printf("|%0*d|", 15, 34982);
	printf("          |%0*d|\n", 15, 34982);
	ft_printf("|%0+*d|", 15, 34982);
	printf("          |%0+*d|\n", 15, 34982);
	ft_printf("|%+0*.7f|", 15, (double)34982);
	printf("          |%+0*.7f|\n", 15, (double)34982);
	ft_printf("|%+###0*.7f|", 15, (double)-9);
	printf("          |%+##0#*.7f|\n", 15, (double)-9);
	ft_printf("|%0###*X|", 15, hexa);
	printf("          |%00###*X|\n", 15, hexa);
	ft_printf("|%0###*x|", 15, hexa);
	printf("          |%0###*x|\n", 15, hexa);
	ft_printf("|%000###*o|", 15, hexa);
	printf("          |%000###*o|\n", 15, hexa);
	ft_printf("|%0*u|", 15, 34982);
	printf("          |%0*u|\n", 15, 34982);
}
