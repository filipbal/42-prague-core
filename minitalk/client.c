/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 10:38:19 by fbalakov          #+#    #+#             */
/*   Updated: 2024/12/12 09:56:16 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	g_current_char = 0;
static int	g_bit_position = 0;

void	handle_signal(int signum, siginfo_t *info, void *context)
{
	(void)context;

	if (signum == SIGUSR2)
		g_current_char |= (1 << g_bit_position);
	g_bit_position++;
	if (g_bit_position == 8)
	{
		ft_putchar_fd(g_current_char, 1);
		g_current_char = 0;
		g_bit_position = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Could not set up signal handlers\n");
		exit(1);
	}
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	setup_signal_handlers();
	while (1)
		pause();
	return (0);
}