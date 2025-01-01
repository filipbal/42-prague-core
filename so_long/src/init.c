/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:52:19 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/01 17:52:19 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Initialize MLX and create window based on map dimensions */
static int	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	
	/* Create window with proper dimensions based on map size and tile size */
	game->win = mlx_new_window(game->mlx, 
		game->map_width * TILE_SIZE,
		game->map_height * TILE_SIZE,
		WINDOW_TITLE);
	if (!game->win)
	{
		free(game->mlx);
		return (0);
	}
	return (1);
}

/* Load all game sprites from XPM files */
int	load_images(t_game *game)
{
	int	width;
	int	height;

	/* Load each sprite and check for errors */
	game->img_player = mlx_xpm_file_to_image(game->mlx, 
		"assets/player.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx, 
		"assets/wall.xpm", &width, &height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx, 
		"assets/white_sock.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx, 
		"assets/exit.xpm", &width, &height);
	
	/* Verify all images loaded successfully */
	if (!game->img_player || !game->img_wall || 
		!game->img_collect || !game->img_exit)
	{
		error_exit("Failed to load one or more sprites", game);
		return (0);
	}
	return (1);
}

/* Initialize game state variables */
static void	init_game_state(t_game *game)
{
	game->collectibles = 0;
	game->collected = 0;
	game->moves = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->exit_x = 0;
	game->exit_y = 0;
}

/* Main initialization function */
int	init_game(t_game *game)
{
	/* First initialize all pointers to NULL for safe cleanup */
	ft_memset(game, 0, sizeof(t_game));
	
	/* Initialize game state variables */
	init_game_state(game);
	
	/* Initialize window and graphics */
	if (!init_window(game))
	{
		error_exit("Failed to initialize window", game);
		return (0);
	}
	
	/* Load game sprites */
	if (!load_images(game))
		return (0);
	
	return (1);
}

/* Clean up allocated resources */
void	cleanup_game(t_game *game)
{
	/* Free sprites if they were loaded */
	if (game->mlx)
	{
		if (game->img_player)
			mlx_destroy_image(game->mlx, game->img_player);
		if (game->img_wall)
			mlx_destroy_image(game->mlx, game->img_wall);
		if (game->img_collect)
			mlx_destroy_image(game->mlx, game->img_collect);
		if (game->img_exit)
			mlx_destroy_image(game->mlx, game->img_exit);
		
		/* Destroy window if it was created */
		if (game->win)
			mlx_destroy_window(game->mlx, game->win);
		
		/* Clean up MLX itself */
		free(game->mlx);
	}
	
	/* Free map if it was allocated */
	if (game->map)
		free_map(game->map, game->map_height);
}

/* Error handling function */
void	error_exit(char *message, t_game *game)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(message, 2);
	ft_putstr_fd("\n", 2);
	cleanup_game(game);
	exit(1);
}