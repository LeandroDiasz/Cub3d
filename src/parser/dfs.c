/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 20:12:34 by ledias-d          #+#    #+#             */
/*   Updated: 2025/09/16 14:57:05 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}

static void	dfs(char **map, int x, int y, int *has_hole)
{
	int	map_height;

	// Se saiu dos limites do mapa, é um buraco
	if (x < 0 || y < 0 || !map[x])
	{
		(*has_hole) = 1;
		return ;
	}
	
	map_height = get_map_height(map);
	
	// Se chegou na primeira ou última linha e não é parede, é buraco
	if ((x == 0 || x == map_height - 1) && map[x][y] != WALL && map[x][y] != ' ')
	{
		(*has_hole) = 1;
		return ;
	}
	
	// Se saiu da string da linha atual
	if (y >= (int)ft_strlen(map[x]))
	{
		(*has_hole) = 1;
		return ;
	}
	
	// Se chegou na primeira ou última coluna e não é parede, é buraco
	if ((y == 0 || y == (int)ft_strlen(map[x]) - 1) && map[x][y] != WALL && map[x][y] != ' ')
	{
		(*has_hole) = 1;
		return ;
	}
	
	// Se já visitou ou é parede, para
	if (map[x][y] == 'V' || map[x][y] == WALL)
		return ;
		
	// Se é espaço vazio, é buraco
	if (map[x][y] == ' ' || map[x][y] == '\0')
	{
		(*has_hole) = 1;
		return ;
	}
	
	// Marca como visitado
	map[x][y] = 'V';
	
	// Continua a busca
	dfs(map, x - 1, y, has_hole);
	dfs(map, x + 1, y, has_hole);
	dfs(map, x, y - 1, has_hole);
	dfs(map, x, y + 1, has_hole);
}

static int	is_valid_walkable_cell(char c)
{
	return (c == FLOOR || c == PLAYER_N || c == PLAYER_S || 
			c == PLAYER_E || c == PLAYER_W);
}

static int	validate_single_area(char **map, int start_x, int start_y)
{
	char	**map_dup;
	int		has_hole;

	map_dup = dup_map(map);
	if (!map_dup)
		return (0);
	has_hole = 0;
	dfs(map_dup, start_x, start_y, &has_hole);
	free_matriz(map_dup);
	return (has_hole == 0);
}

static int	validate_all_walkable_areas(char **map)
{
	int		i;
	int		j;
	char	**visited;

	visited = dup_map(map);
	if (!visited)
		return (0);
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_valid_walkable_cell(map[i][j]) && visited[i][j] != 'V')
			{
				if (!validate_single_area(map, i, j))
				{
					free_matriz(visited);
					return (0);
				}
				dfs(visited, i, j, &(int){0});
			}
			j++;
		}
		i++;
	}
	free_matriz(visited);
	return (1);
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
	int		player_x;
	int		player_y;

	if (!validate_map_structure(map))
		return (0);
	if (!find_player(map, &player_x, &player_y))
		return (0);
	if (!validate_all_walkable_areas(map))
	{
		printf("Error: Map contains invalid areas or holes\n");
		return (0);
	}
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

