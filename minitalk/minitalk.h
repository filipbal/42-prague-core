/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:38:19 by fbalakov          #+#    #+#             */
/*   Updated: 2024/12/12 09:56:16 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* Standard includes needed for our signal handling and basic operations */
# include <signal.h>    /* For signal(), sigaction(), kill() */
# include <unistd.h>    /* For write(), getpid(), pause(), sleep(), usleep() */
# include <stdlib.h>    /* For exit(), malloc(), free() */
# include <stdarg.h>    /* For variadic functions in ft_printf */

/* Error messages for better code organization */
# define ERR_USAGE "Usage: ./client [server_pid] [message]\n"
# define ERR_PID "Error: Invalid PID\n"
# define ERR_SIGNAL "Error: Signal failure\n"
# define ERR_MEMORY "Error: Memory allocation failed\n"

/* Utility function prototypes from our simplified printf */
int     ft_printf(const char *format, ...);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char *s, int fd);
void    ft_putnbr_fd(int n, int fd);

/* Signal handling prototypes - we'll implement these in server.c */
void    setup_signal_handlers(void);
void    handle_signal(int signum, siginfo_t *info, void *context);

/* Client function prototypes - we'll implement these in client.c */
void    send_message(pid_t server_pid, const char *message);
void    send_char(pid_t server_pid, char c);

#endif