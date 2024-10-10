/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:38:19 by fbalakov          #+#    #+#             */
/*   Updated: 2024/10/10 11:28:04 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// for dev
#include <stdio.h>
#include <string.h>

int ft_printf(const char *, ...);

int main(void) {
	// cspdiuxX%
	char			character = 'G';
	char			string[] = "Bali";
	void 			*pointer = 0x000000;
	int				decimal = 21;
	int				integer = 2147483647;
	unsigned int	uInteger = 2147483648;
	unsigned int	hexadecimal = 0xaf0000;
	unsigned int	Hexadecimal = 0xAF0000;

	printf("Character: %c Pointer: %p String: %s Decimal: %d Integer: %i Unsigned: %u hex: %x HEX: %X %%: %% The END\n", character, pointer, string, decimal, integer, uInteger, hexadecimal, Hexadecimal);	
	ft_printf("Character: %c Pointer: %p String: %s Decimal: %d Integer: %i Unsigned: %u hex: %x HEX: %X %%: %% The END\n", character, pointer, string, decimal, integer, uInteger, hexadecimal, Hexadecimal);

	return 0;
}

// TODO RETURN INT OF CHARS PRINTED
int ft_printf(const char* format, ...) {
    va_list args;
    va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				char c = va_arg(args, int);
				ft_putchar_fd(c, 1);
			}
			else if (*format == 's')
			{
				char* str = va_arg(args, char*);
				ft_putstr_fd(str, 1);
			}
			else if (*format == 'p')
			{
				void* ptr = va_arg(args, void*);
				if (ptr == NULL)
					ft_putstr_fd("(nil)", 1);
				else
				{
					ft_putstr_fd("0x", 1);
					ft_puthex((unsigned long)ptr, 0);
				}
			} 
			else if (*format == 'd' || *format == 'i' )
			{
				int num = va_arg(args, int);
				ft_putnbr_fd(num, 1);
			}
			else if (*format == 'u')
			{
				unsigned int unum = va_arg(args, unsigned int);
				if (unum >= 10)
					ft_printf("%u", unum / 10);
				ft_putchar_fd((unum % 10) + '0', 1);
			}
			else if (*format == 'x')
			{
				unsigned int hex = va_arg(args, unsigned int);
				ft_puthex(hex, 0);
			}
			else if (*format == 'X')
			{
				unsigned int HEX = va_arg(args, unsigned int);
				ft_puthex(HEX, 1);
			}
			else if (*format == '%')
			{
				ft_putchar_fd(*format, 1);
			}
			format++;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			format++;
		}
	}

    va_end(args);
	return 0;
}