/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 15:12:23 by franmore          #+#    #+#             */
/*   Updated: 2025-04-06 15:12:23 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_asign_colors(t_point_map **map, int min, int max)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (x < map[0]->array_length)
		{
			if (map[y][x].z == 0)
				map[y][x].color = COLOR_DEFAULT;
			if (map[y][x].z > 0)
				map[y][x].color = ft_interpolate_color(COLOR_DEFAULT,
						COLOR_HIGH, (float)map[y][x].z / (float)max);
			if (map[y][x].z < 0)
				map[y][x].color = ft_interpolate_color(COLOR_DEFAULT,
						COLOR_LOW, (float)map[y][x].z / (float)min);
			x ++;
		}
		y ++;
	}
}

void	ft_asign_colors_aux(t_point_map **map)
{
	int	y;
	int	x;
	int	min;
	int	max;

	y = 0;
	min = map[0][0].z;
	max = min;
	while (map[y])
	{
		x = 0;
		while (x < map[0]->array_length)
		{
			if (min > map[y][x].z)
				min = map[y][x].z;
			if (max < map[y][x].z)
				max = map[y][x].z;
			x ++;
		}
		y ++;
	}
	ft_asign_colors(map, min, max);
}
