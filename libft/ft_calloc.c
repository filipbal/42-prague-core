/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:02:48 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 17:27:22 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_calloc allocates memory for an array of count elements, each of size bytes
// It initializes the allocated memory to zero.
// It returns a pointer to the allocated memory or NULL if the allocation fails.

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count);
	return (ptr);
}
