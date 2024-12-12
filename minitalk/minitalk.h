/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:44:52 by fbalakov          #+#    #+#             */
/*   Updated: 2024/12/12 12:44:52 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

/* For signal(), sigaction(), kill() */
# include <signal.h>
/* For write(), getpid(), pause(), sleep(), usleep() */
# include <unistd.h>
/* For exit(), malloc(), free() */
# include <stdlib.h>
/* For variadic functions in ft_printf */
# include <stdarg.h>

/* Error messages */
# define ERR_USAGE "Usage: ./client [server_pid] [message]\n"
# define ERR_PID "Error: Invalid PID\n"
# define ERR_SIGNAL "Error: Signal failure\n"
# define ERR_MEMORY "Error: Memory allocation failed\n"

/* Utility function prototypes from simplified printf */
int		ft_printf(const char *format, ...);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

/* Signal handling prototypes - in server.c */
void	setup_signal_handlers(void);
void	handle_signal(int signum, siginfo_t *info, void *context);

/* Client function prototypes - in client.c */
void	send_message(pid_t server_pid, const char *message);
void	send_char(pid_t server_pid, char c);

#endif