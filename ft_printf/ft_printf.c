/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 10:38:19 by fbalakov          #+#    #+#             */
/*   Updated: 2024/05/29 18:15:34 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// returns a number of % characters in a string
int ft_printf(const char *, ...);

int main (void)
{
	char 	str[100] = "My name is %s and I am %d years old.";
	int		count;
	int		i;
	
	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			count++;
		i++;
	}
	count += 48;
	write(1, &count , 1);
	write(1, "\n" , 1);
	return (0);
}