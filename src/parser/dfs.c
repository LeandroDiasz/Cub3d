/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:12:34 by ledias-d          #+#    #+#             */
/*   Updated: 2025/09/06 11:21:52 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	dfs(char **map, int x, int y, int *has_hole)
{
	if (x < 0 || y < 0 || !map[x] || map[x][y] == WALL)
		return ;
	if (y >= (int)ft_strlen(map[x]))
	{
		(*has_hole) = 1;
		return ;
	}
	if (map[x][y] == 'V')
		return ;
	if (map[x][y] == ' ' || map[x][y] == '\0')
	{
		(*has_hole) = 1;
		return ;
	}
	map[x][y] = 'V';
	dfs(map, x - 1, y, has_hole);
	dfs(map, x + 1, y, has_hole);
	dfs(map, x, y - 1, has_hole);
	dfs(map, x, y + 1, has_hole);
}

static int	validate_map_structure(char **map)
{
	int	i;
	int	j;
	int	len;

	if (!map || !map[0])
		return (0);
	i = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		j = 0;
		while (j < len)
		{
			if (map[i][j] != WALL && map[i][j] != FLOOR && 
				map[i][j] != PLAYER_N && map[i][j] != PLAYER_S && 
				map[i][j] != PLAYER_E && map[i][j] != PLAYER_W && 
				map[i][j] != ' ')
			{
				printf("Error: Invalid character '%c' at position [%d][%d]\n", 
					map[i][j], i, j);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	map_validate(char **map)
{
	char	**map_dup;
	int		player_x;
	int		player_y;
	int		flag;

	if (!validate_map_structure(map))
		return (0);
	flag = 0;
	map_dup = dup_map(map);
	if (!map_dup)
		return (0);
	if (!find_player(map, &player_x, &player_y))
	{
		free_matriz(map_dup);
		return (0);
	}
	dfs(map_dup, player_x, player_y, &flag);
	if (flag == 1)
	{
		printf("Error: Map is not closed\n");
		free_matriz(map_dup);
		return (0);
	}
	free_matriz(map_dup);
	return (1);
}


int	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;
	int	player_count;

	i = 0;
	player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == PLAYER_W || map[i][j] == PLAYER_E
				|| map[i][j] == PLAYER_N || map[i][j] == PLAYER_S)
			{
				*x = i;
				*y = j;
				player_count++;
			}
			j++;
		}
		i++;
	}
	if (player_count != 1)
	{
		if (player_count == 0)
			printf("Error: No player found in map\n");
		else
			printf("Error: Multiple players found in map\n");
		return (0);
	}
	return (1);
}

