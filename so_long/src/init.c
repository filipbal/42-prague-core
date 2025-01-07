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
/* Calculate window dimensions */
/* Create window with calculated dimensions */
static int	init_window(t_game *game)
{
	int	window_width;
	int	window_height;

	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Debug: MLX initialization failed\n");
		return (0);
	}
	window_width = game->map_width * TILE_SIZE;
	window_height = game->map_height * TILE_SIZE;
	if (window_width <= 0 || window_height <= 0)
	{
		free(game->mlx);
		return (0);
	}
	game->win = mlx_new_window(game->mlx, window_width, window_height,
			WINDOW_TITLE);
	if (!game->win)
	{
		ft_printf("Debug: Window creation failed\n");
		free(game->mlx);
		return (0);
	}
	return (1);
}

/* Load all game sprites from XPM files  */
/* Verify all images loaded successfully */
/* Load each sprite and check for errors */
int	load_images(t_game *game)
{
	int	width;
	int	height;

	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"assets/player.xpm", &width, &height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"assets/wall.xpm", &width, &height);
	game->img_collect = mlx_xpm_file_to_image(game->mlx,
			"assets/bone.xpm", &width, &height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"assets/exit.xpm", &width, &height);
	if (!game->img_player || !game->img_wall
		|| !game->img_collect || !game->img_exit)
	{
		error_exit("Failed to load one or more sprites", game);
		return (0);
	}
	return (1);
}

/* Initialize window */
/* Load game sprites */
/* Setup event hooks */
int	init_game(t_game *game)
{
	ft_printf("Debug: init_game - dimensions before: %dx%d\n",
		game->map_width, game->map_height);
	if (!init_window(game))
	{
		error_exit("Failed to initialize window", game);
		return (0);
	}
	ft_printf("Debug: init_game - dimensions after window init: %dx%d\n",
		game->map_width, game->map_height);
	if (!load_images(game))
	{
		error_exit("Failed to load images", game);
		return (0);
	}
	mlx_key_hook(game->win, handle_keypress, game);
	mlx_hook(game->win, 17, 0L, handle_close, game);
	mlx_expose_hook(game->win, handle_expose, game);
	ft_printf("Debug: Game initialization successful\n");
	return (1);
}

/* Free sprites if they were loaded */
/* Destroy window if it was created */
/* Free map if it was allocated */
/* Don't free game->mlx - it's handled by mlx_destroy_window */
void	cleanup_game(t_game *game)
{
	if (!game)
		return ;
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
		if (game->win)
		{
			mlx_destroy_window(game->mlx, game->win);
			game->win = NULL;
		}
	}
	if (game->map)
	{
		free_map(game->map, game->map_height);
		game->map = NULL;
	}
	game->mlx = NULL;
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
