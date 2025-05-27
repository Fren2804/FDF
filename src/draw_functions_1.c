/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 11:47:08 by franmore          #+#    #+#             */
/*   Updated: 2025-03-27 11:47:08 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	my_mlx_pixel_put(t_general *gen, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= gen->width || y < 0 || y >= gen->height)
		return ;
	dst = gen->addr + (y * gen->size_length + x * (gen->bits_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_interpolate_color(int color1, int color2, float t)
{
	int	r;
	int	g;
	int	b;

	r = (int)(((color2 >> 16) & 0xFF) * t + ((color1 >> 16) & 0xFF) * (1 - t));
	g = (int)(((color2 >> 8) & 0xFF) * t + ((color1 >> 8) & 0xFF) * (1 - t));
	b = (int)((color2 & 0xFF) * t + (color1 & 0xFF) * (1 - t));
	return ((r << 16) | (g << 8) | b);
}

static void	ft_draw_lines_iso(t_general *general, t_point_map **map)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (x < map[y]->array_length)
		{
			if (map[y + 1])
			{
				ft_abajo_iso(general, map, x, y);
			}
			if (x + 1 < map[y]->array_length)
			{
				ft_derecha_iso(general, map, x, y);
			}
			x ++;
		}
		y ++;
	}
}

static void	ft_draw_lines_no_iso(t_general *general, t_point_map **map)
{
	int	x;
	int	y;

	y = 0;
	ft_scale(map);
	while (map[y])
	{
		x = 0;
		while (x < map[y]->array_length)
		{
			if (map[y + 1])
			{
				ft_abajo_no_iso(general, map, x, y);
			}
			if (x + 1 < map[y]->array_length)
			{
				ft_derecha_no_iso(general, map, x, y);
			}
			x ++;
		}
		y ++;
	}
}

void	ft_draw_lines(t_general *general, t_point_map **map)
{
	ft_scale(map);
	if (general->iso)
		ft_draw_lines_iso(general, map);
	else
		ft_draw_lines_no_iso(general, map);
	mlx_put_image_to_window((*general).mlx, (*general).win,
		(*general).img, 0, 0);
}
