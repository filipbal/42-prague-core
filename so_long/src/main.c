/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:00:11 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/10 09:59:20 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Validate file extension (.ber) */
static int	check_file_extension(char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (!ft_strncmp(filename + len - 4, ".ber", 4));
}

/* Initialize game structure, validate inputs, parse map, initialize graphics,
** and start game loop. All errors exit with error message to stderr. */
int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		error_exit("Usage: ./so_long <map_file.ber>", &game);
	if (!check_file_extension(argv[1]))
		error_exit("Invalid file extension (must be .ber)", &game);
	if (!parse_map(&game, argv[1]))
		error_exit("Invalid map configuration", &game);
	if (!init_game(&game))
		error_exit("Failed to initialize game", &game);
	ft_printf("Welcome to Betty's Adventure!\n");
	ft_printf("Collect all %d bones and reach the bed!\n", game.collectibles);
	ft_printf("Use WASD or arrow keys to move\n");
	render_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
