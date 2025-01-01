/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbalakov <fbalakov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 18:02:22 by fbalakov          #+#    #+#             */
/*   Updated: 2025/01/01 18:02:22 by fbalakov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Count lines in a file */
/* Count total number of lines in a file */
int    count_lines(char *filename)
{
    int        fd;
    int        lines;
    char    *line;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (-1);
    
    lines = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)  /* End of file or error */
            break;
        lines++;
        free(line); /* Important: free the line after counting */
    }
    close(fd);
    
    return (lines);
}

/* Create a copy of the map for validation purposes */
char	**map_copy(char **map, int height)
{
	char	**copy;
	int		i;

	copy = (char **)malloc(sizeof(char *) * height);
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	return (copy);
}

/* Calculate window dimensions based on map size */
void	get_window_size(t_game *game, int *width, int *height)
{
	*width = game->map_width * TILE_SIZE;
	*height = game->map_height * TILE_SIZE;
	
	/* Ensure window size doesn't exceed screen dimensions */
	if (*width > 2560)
		*width = 2560;
	if (*height > 1440)
		*height = 1440;
}

/* Print game statistics */
void	print_game_stats(t_game *game)
{
	ft_printf("\nGame Statistics:\n");
	ft_printf("Map size: %dx%d\n", game->map_width, game->map_height);
	ft_printf("Collectibles: %d\n", game->collectibles);
	ft_printf("Moves made: %d\n", game->moves);
}

/* Debug function to print current map state */
void	debug_print_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_height)
	{
		ft_printf("%s\n", game->map[i]);
		i++;
	}
}