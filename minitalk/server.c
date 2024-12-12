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
	(void)context;  // Unused parameter

	if (signum == SIGUSR2)
		g_current_char |= (1 << g_bit_position);
	g_bit_position++;

	// When we've received all 8 bits of a character
	if (g_bit_position == 8)
	{
		ft_putchar_fd(g_current_char, 1);
		g_current_char = 0;
		g_bit_position = 0;
	}
	// Send acknowledgment signal back to client
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
	sa.sa_flags = SA_SIGINFO;  // Enable extended signal handling
	sigemptyset(&sa.sa_mask);

	// Register handlers for both SIGUSR1 and SIGUSR2
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error: Could not set up signal handlers\n");
		exit(1);
	}
}

int	main(void)
{
	// Print server's PID so clients can connect
	ft_printf("Server PID: %d\n", getpid());
	
	// Set up signal handlers
	setup_signal_handlers();

	// Keep the server running indefinitely
	while (1)
		pause();  // Pause until a signal is received
	return (0);
}