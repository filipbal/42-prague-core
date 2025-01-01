/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:39:44 by fbalakov          #+#    #+#             */
/*   Updated: 2024/10/25 13:41:19 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/* If BUFFER_SIZE not defined during compile, give it a default */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/* Function prototype */
char	*get_next_line(int fd);

/* Helper function prototypes */
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(const char *s, int c);
size_t	ft_strlen_gnl(const char *s);
char	*read_and_append(int fd, char *stash, char *buffer);

#endif