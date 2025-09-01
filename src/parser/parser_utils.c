/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 17:04:23 by codespace         #+#    #+#             */
/*   Updated: 2025/09/01 17:41:49 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_ext(const char *file)
{
	int	i;
	int	j;

	if (!file && ft_strlen(file) < 4)
		error_exit("Error: null file or insufficient size", NULL);
	i = ft_strlen(file) - 4;
	j = 0;
	while (".cub"[j])
	{
		if (file[i + j] != ".cub"[j])
		{
			printf("Error: Invalid extension. Use .cub\n");
			return (0);
		}
		j++;
	}
	return (1);
}

char    **dup_map(char **map)
{
    char    **map_dup;
    int     i;

    i = 0;
    while (map[i])
        i++;
    map_dup = (char **)ft_calloc(i + 1, sizeof(char *));
    if (!map_dup)
        return (NULL);
    i = 0;
    while (map[i])
    {
        map_dup[i] = ft_strdup(map[i]);
        if (!map_dup[i])
        {
            free_matriz(map_dup);
            return (NULL);
        }
        i++;
    }
    map_dup[i] = NULL;
    return (map_dup);
}