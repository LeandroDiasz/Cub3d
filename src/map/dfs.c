/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:12:34 by ledias-d          #+#    #+#             */
/*   Updated: 2025/08/29 21:04:23 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	map_validate(char **map)
{
	char	**map_dup;
	int		player_x;
	int		player_y;
	int		flag;

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

static void	dfs(char **map, int x, int y, int *has_hole)
{
	if (x < 0 || y < 0 || !map[x] || !map[x][y] || map[x][y] == WALL)
		return ;
	if (map[x][y] == 'V')
		return ;
	if (map[x][y] == ' ')
	{
		(*has_hole) = 1;
		return ;
	}
	if ((*has_hole) == 1)
		return ;
	map[x][y] = 'V';
	dfs(map, x - 1, y, &has_hole);
	dfs(map, x + 1, y, &has_hole);
	dfs(map, x, y - 1, &has_hole);
	dfs(map, x, y + 1, &has_hole);
}

static int	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
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
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

