/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:47:02 by fbalakov          #+#    #+#             */
/*   Updated: 2024/12/12 12:47:02 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

/*
 * Global variable to store the current character being received.
 * We use a global because signal handlers need access to persistent data
 * between calls.
 */
static char	g_current_char = 0;
static int	g_bit_position = 0;

/*
 * Signal handler function that processes incoming SIGUSR1 and SIGUSR2 signals.
 * SIGUSR1 represents a 0 bit
 * SIGUSR2 represents a 1 bit
 */
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

/*
 * Sets up the signal handlers using sigaction.
 * We use sigaction instead of signal() because it's more reliable and
 * provides more information about the signal, including the sender's PID.
 */
void	setup_signal_handlers(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Could not set up signal handlers\n");
		exit(1);
	}
}

// Print server's PID so clients can connect
// Set up signal handlers
// Keep the server running indefinitely
// Pause until a signal is received
int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	setup_signal_handlers();
	while (1)
		pause();
	return (0);
}
