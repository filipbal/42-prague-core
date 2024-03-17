/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:50:01 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 15:52:03 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_striteri applies the given function f to each char in the input string s.
// Unlike ft_strmapi, which creates a new string based on the results,
// ft_striteri modifies the original string in place.

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
