/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_prop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:40:08 by ledias-d          #+#    #+#             */
/*   Updated: 2025/09/06 11:21:08 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int set_textures(char **file, t_cub3d *game, int *y)
{
	while (file[*y])
	{
		if (file[*y][0] == '\n' || file[*y][0] == '\0')
		{
			(*y)++;
			continue;
		}
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
		else
			break ;
		(*y)++;
	}
	return (1);
}

static int	validate_required_textures(t_cub3d *game)
{
	if (!game->no_texture)
	{
		printf("Error: North texture (NO) not defined\n");
		return (0);
	}
	if (!game->so_texture)
	{
		printf("Error: South texture (SO) not defined\n");
		return (0);
	}
	if (!game->we_texture)
	{
		printf("Error: West texture (WE) not defined\n");
		return (0);
	}
	if (!game->ea_texture)
	{
		printf("Error: East texture (EA) not defined\n");
		return (0);
	}
	if (!game->floor_color)
	{
		printf("Error: Floor color (F) not defined\n");
		return (0);
	}
	if (!game->ceiling_color)
	{
		printf("Error: Ceiling color (C) not defined\n");
		return (0);
	}
	return (1);
}

int	cub_validate(char **file, t_cub3d *game)
{
	int	y;
	
	y = 0;
	if (!set_textures(file, game, &y))
		return (0);
	if (!validate_required_textures(game))
		return (0);
	while (file[y] && (file[y][0] == '\n' || file[y][0] == '\0' || 
		   (ft_strlen(file[y]) == 1 && file[y][0] == ' ')))
		y++;
	if (!file[y])
	{
		printf("Error: No map found in file\n");
		return (0);
	}
	game->map = &file[y];
	if (!game->map || !*game->map)
		return (0);
	return (1);
}
