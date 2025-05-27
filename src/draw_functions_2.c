/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 12:33:07 by franmore          #+#    #+#             */
/*   Updated: 2025-04-06 12:33:07 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_rotate_z(t_point *point, float angle)
{
	float	x;
	float	y;

	x = (float)point->x;
	y = (float)point->y;
	point->x = (int) x * cos(angle) - y * sin(angle);
	point->y = (int) x * sin(angle) + y * cos(angle);
}

static void	ft_scale_aux(t_point_map **map, int min, int max)
{
	if (max - min < 10)
		map[0]->scale = 20;
	else if (max - min < 40)
		map[0]->scale = 10;
	else
		map[0]->scale = 1;
}

void	ft_scale(t_point_map **map)
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
	ft_scale_aux(map, min, max);
}

static float	ft_inc(int value1, int value2, int steps)
{
	float	diff;
	float	inc;

	diff = value2 - value1;
	inc = diff / steps;
	return (inc);
}

void	ft_draw_line(t_general *general, t_point point1, t_point point2)
{
	float	x;
	float	y;
	int		steps;
	int		color;
	int		i;

	steps = fmax(fabs((double)(point2.x - point1.x)),
			fabs((double)(point2.y - point1.y)));
	x = point1.x;
	y = point1.y;
	i = 0;
	while (i <= steps)
	{
		color = ft_interpolate_color(point1.color, point2.color,
				(float)i / steps);
		my_mlx_pixel_put(general, (int)x, (int)y, color);
		x += ft_inc(point1.x, point2.x, steps);
		y += ft_inc(point1.y, point2.y, steps);
		i++;
	}
}
