/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 08:59:48 by fbalakov          #+#    #+#             */
/*   Updated: 2024/10/22 09:48:55 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ft_printf.h */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

/* Public function prototypes */
int		ft_printf(const char *format, ...);

/* Internal function prototypes */
int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_ptr(void *ptr);
int		ft_print_int(int n);
int		ft_print_uint(unsigned int n);
int		ft_print_hex(unsigned int n, int is_upper);
int		ft_print_percent(void);

/* Utility function prototypes */
int		ft_count_digits(int n);
int		ft_count_uint_digits(unsigned int n);
void	ft_put_uint_fd(unsigned int n, int fd);
int		ft_put_hex(unsigned long n, int is_upper);

#endif