/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:27:50 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/10 13:04:25 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include <mlx.h>
# include <fcntl.h>

/* Game constants */
# define TILE_SIZE 64
# define WINDOW_TITLE "Betty's Adventure"

/* Key codes for Linux/WSL */
# define KEY_ESC     65307
# define KEY_W       119
# define KEY_A       97
# define KEY_S       115
# define KEY_D       100
# define KEY_UP      65362
# define KEY_LEFT    65361
# define KEY_DOWN    65364
# define KEY_RIGHT   65363

/* Map elements */
# define EMPTY       '0'
# define WALL        '1'
# define PLAYER      'P'
# define COLLECT     'C'
# define EXIT        'E'

/* Main game structure */
typedef struct s_game
{
	/* MLX pointers */
	void	*mlx;			/* Main MLX pointer */
	void	*win;			/* Window pointer */
	/* Map data */
	char	**map;			/* 2D array to store the map */
	int		map_width;		/* Width of the map in tiles */
	int		map_height;		/* Height of the map in tiles */
	/* Game state */
	int		player_x;		/* Player's X position */
	int		player_y;		/* Player's Y position */
	int		collectibles;	/* Total number of collectibles */
	int		collected;		/* Number of collected items */
	int		moves;			/* Number of moves made */
	int		exit_x;			/* Exit X position */
	int		exit_y;			/* Exit Y position */
	/* Sprite images */
	void	*img_player;	/* Player sprite */
	void	*img_wall;		/* Wall sprite */
	void	*img_collect;	/* Collectible sprite */
	void	*img_exit;		/* Exit sprite */
	void	*img_floor;		/* Floor/empty space sprite */
}	t_game;

/* Initialization functions */
void	init_game(t_game *game);
void	load_images(t_game *game);

/* Map functions */
void	parse_map(t_game *game, char *filename);
void	free_map(char **map, int height);
int		check_walls(t_game *game);
int		check_elements(t_game *game);
int		check_path(t_game *game);
void	update_element_counts(t_game *game, int i, int j, int counts[3]);
void	flood_fill(char **map, int x, int y, int *collectibles);
int		validate_map(t_game *game);

/* Game logic functions */
int		handle_keypress(int keycode, t_game *game);
int		handle_close(t_game *game);
int		handle_expose(t_game *game);
void	update_game_state(t_game *game);
void	render_game(t_game *game);
void	cleanup_game(t_game *game);
void	error_exit(char *message, t_game *game);

#endif