/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 17:27:50 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/01 17:27:50 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* Required library includes */
# include "../libft/libft.h"          /* Include libft first */
# include "../ft_printf/ft_printf.h"   /* Then include ft_printf */
# include "../get_next_line/get_next_line.h"
# include <mlx.h>			/* MiniLibX graphics library */
# include <stdlib.h>       /* For memory management functions */
# include <fcntl.h>        /* For open() */
# include <unistd.h>       /* For close() */

/* Define key codes for Linux/WSL */
# define KEY_ESC     65307
# define KEY_W       119
# define KEY_A       97
# define KEY_S       115
# define KEY_D       100
# define KEY_UP      65362
# define KEY_LEFT    65361
# define KEY_DOWN    65364
# define KEY_RIGHT   65363

/* Define window properties */
# define TILE_SIZE   32
/* Change the window title */
# define WINDOW_TITLE "Betty's Adventure - So Long"

/* Define map characters */
# define EMPTY       '0'
# define WALL        '1'
# define PLAYER      'P'
# define COLLECT     'C'
# define EXIT        'E'

/* Main game structure to hold all necessary data */
typedef struct s_game
{
    /* MLX pointers */
    void    *mlx;           /* Main MLX pointer */
    void    *win;           /* Window pointer */
    
    /* Map data */
    char    **map;          /* 2D array to store the map */
    int     map_width;      /* Width of the map in tiles */
    int     map_height;     /* Height of the map in tiles */
    
    /* Game state */
    int     player_x;       /* Player's X position */
    int     player_y;       /* Player's Y position */
    int     collectibles;   /* Total number of collectibles */
    int     collected;      /* Number of collected items */
    int     moves;          /* Number of moves made */
    int     exit_x;         /* Exit X position */
    int     exit_y;         /* Exit Y position */
    
    /* Sprite images */
    void    *img_player;    /* Player sprite */
    void    *img_wall;      /* Wall sprite */
    void    *img_collect;   /* Collectible sprite */
    void    *img_exit;      /* Exit sprite */
    void    *img_floor;     /* Floor/empty space sprite */
}   t_game;

/* Function prototypes */

/* Initialization functions */
int     init_game(t_game *game);
int     load_images(t_game *game);

/* Map handling functions */
int     parse_map(t_game *game, char *filename);
int     validate_map(t_game *game);
// int     check_path(t_game *game);

/* Game logic functions */
int     handle_keypress(int keycode, t_game *game);
void    move_player(t_game *game, int new_x, int new_y);
void    update_game_state(t_game *game);

/* Rendering functions */
void    render_game(t_game *game);
// void    render_tile(t_game *game, void *img, int x, int y);

/* Error handling and cleanup */
void    cleanup_game(t_game *game);
void    error_exit(char *message, t_game *game);
void    free_map(char **map, int height);

void    setup_events(t_game *game);

#endif