/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 19:13:54 by ledias-d          #+#    #+#             */
/*   Updated: 2025/08/29 21:04:32 by ledias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include "cub3d.h"

char	**file_read(char *file);
int		count_lines(char *file);
char	*get_next_line(int fd);
int		cub_validate(char **file, t_cub3d *game);
int		map_validate(char **map);

#endif