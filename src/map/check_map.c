/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ledias-d <ledias-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 18:56:16 by ledias-d          #+#    #+#             */
/*   Updated: 2025/08/29 18:57:42 by ledias-d         ###   ########.fr       */
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
			ft_printf("Error: Invalid extension. Use .cub\n");
			return (0);
		}
		j++;
	}
	return (1);
}