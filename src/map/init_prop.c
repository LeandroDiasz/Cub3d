/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:40:08 by ledias-d          #+#    #+#             */
/*   Updated: 2025/08/29 19:53:35 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int set_textures(char **file, t_cub3d *game, int *y)
{
	while (file[*y])
	{
		if (ft_strncmp(file[*y], "NO ", 3) == 0)
			game->no_texture = ft_strtrim(file[*y] + 3, "\n");
		else if (ft_strncmp(file[*y], "SO ", 3) == 0)
			game->so_texture = ft_strtrim(file[*y] + 3, "\n");
		else if (ft_strncmp(file[*y], "WE ", 3) == 0)
			game->we_texture = ft_strtrim(file[*y] + 3, "\n");
		else if (ft_strncmp(file[*y], "EA ", 3) == 0)
			game->ea_texture = ft_strtrim(file[*y] + 3, "\n");
		else if (ft_strncmp(file[*y], "F ", 2) == 0)
			game->floor_color = ft_strtrim(file[*y] + 2, "\n");
		else if (ft_strncmp(file[*y], "C ", 2) == 0)
			game->ceiling_color = ft_strtrim(file[*y] + 2, "\n");
		else if (file[*y] == '\n')
			(*y)++;
		else
			break ;
		(*y)++;
	}
	return (1);
}

int	cub_validate(char **file, t_cub3d *game)
{
	int	y;
	y = 0;
	if (!set_textures(file, game, &y))
		return (0);
	while (file[y] && file[y][0] == '\n')
		(y)++;
	game->map = &file[y];
	if (!game->map || !*game->map)
		return (0);
	return (1);
}