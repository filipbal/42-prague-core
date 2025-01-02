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

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (!ft_strncmp(filename + len - 4, ".ber", 4));
}

/* Initialize and start the game */
static int    start_game(char *map_file)
{
    t_game  game;

    /* Initialize all game variables to 0/NULL */
    ft_memset(&game, 0, sizeof(t_game));

    /* Parse and validate the map */
    if (!parse_map(&game, map_file))
    {
        ft_printf("Error\nInvalid map configuration\n");
        cleanup_game(&game);  // We need this even on parse failure
        return (0);
    }

    ft_printf("Debug: After parse_map - dimensions: %dx%d\n", game.map_width, game.map_height);

    /* Initialize the game engine and window */
    if (!init_game(&game))
    {
        ft_printf("Error\nFailed to initialize game\n");
        cleanup_game(&game);
        return (0);
    }

    /* Set up event handlers */
    setup_events(&game);

    /* Display initial game state */
    ft_printf("Welcome to Betty's Adventure!\n");
    ft_printf("Collect all %d bones and reach the bed!\n", game.collectibles);
    ft_printf("Use WASD or arrow keys to move\n");
    
    /* Render initial game state */
    render_game(&game);

    /* Start the game loop */
    mlx_loop(game.mlx);
    return (1);
}

int	main(int argc, char **argv)
{
	/* Check if correct number of arguments provided */
	if (argc != 2)
	{
		ft_printf("Error\nUsage: ./so_long <map_file.ber>\n");
		return (1);
	}

	/* Validate file extension */
	if (!check_file_extension(argv[1]))
	{
		ft_printf("Error\nInvalid file extension (must be .ber)\n");
		return (1);
	}

	/* Start the game with provided map file */
	if (!start_game(argv[1]))
		return (1);

	return (0);
}