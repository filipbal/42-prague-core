/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 15:55:17 by fbalakov          #+#    #+#             */
/*   Updated: 2024/03/17 15:59:15 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ft_putstr_fd writes the given string (s) to a specified file descriptor (fd).
// It uses the write system call to perform the writing operation.
// It relies on ft_strlen, to get the length of the input string.

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	write(fd, s, ft_strlen(s));
}
