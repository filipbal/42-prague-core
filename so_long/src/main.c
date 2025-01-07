/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:00:11 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/01 18:00:11 by fbalakov         ###   ########.fr       */
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

/* 
** Initialize all game variables to 0/NULL
** Parse and validate the map
** Initialize the game engine and window
** Set up event handlers
** Display initial game state
** Render initial game state
** Start the game loop 
*/
static int	start_game(char *map_file)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (!parse_map(&game, map_file))
	{
		ft_printf("Error\nInvalid map configuration\n");
		cleanup_game(&game);
		return (0);
	}
	if (!init_game(&game))
	{
		ft_printf("Error\nFailed to initialize game\n");
		cleanup_game(&game);
		return (0);
	}
	ft_printf("Welcome to Betty's Adventure!\n");
	ft_printf("Collect all %d bones and reach the bed!\n", game.collectibles);
	ft_printf("Use WASD or arrow keys to move\n");
	render_game(&game);
	mlx_loop(game.mlx);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map_file.ber>\n");
		return (1);
	}
	if (!check_file_extension(argv[1]))
	{
		ft_printf("Error\nInvalid file extension (must be .ber)\n");
		return (1);
	}
	return (!start_game(argv[1]));
}
