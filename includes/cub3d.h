/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 15:57:26 by leandrodias       #+#    #+#             */
/*   Updated: 2025/08/29 19:48:07 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../Libft/libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include "parser.h"
# include "map.h"

# define BUFFER_SIZE 1024
# define WIN_NAME "Cub3D"
# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define ESC_KEY 65307
# define KEY_ARROW_RIGHT 100
# define KEY_ARROW_LEFT 97
# define KEY_ARROW_UP 119
# define KEY_ARROW_DOWN 115


typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	int		width;
	int		height;
	char	**map;
	char	**file;
	int		player_x;
	int		player_y;
	int		player_dir; // 0: North, 1: East, 2: South, 3: West
	int		map_width;
	int		map_height;
	char	*no_texture;
	char	*so_texture;
	char	*we_texture;
	char	*ea_texture;
	char	*floor_color;
	char	*ceiling_color;
	int		floor_rgb;
	int		ceiling_rgb;
}	t_cub3d;

int		init_cub3d(t_cub3d *game, char *file);
int		start_game(t_cub3d *game);
void	multi_free(void *first, ...);

#endif