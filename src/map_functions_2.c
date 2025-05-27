/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 11:56:37 by franmore          #+#    #+#             */
/*   Updated: 2025-04-06 11:56:37 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_free_map_point(t_point_map **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i ++;
	}
	free(map);
}

void	ft_free_map_char(char **map_char)
{
	int	i;

	i = 0;
	while (map_char[i])
	{
		free(map_char[i]);
		i ++;
	}
	free(map_char);
}

int	ft_obtain_color_hex(char hex)
{
	int	i;

	i = 0;
	while (HEX_LOW[i])
	{
		if (ft_tolower((int) hex) == (int) HEX_LOW[i])
			return (i);
		i ++;
	}
	return (0);
}

void	ft_obtain_point_color(t_point_map *point, char	**point_char)
{
	int	i;
	int	len_color;

	len_color = ft_strlen(point_char[1]);
	i = 0;
	(*point).color = 0;
	if (point_char[1][len_color - 1] == '\n')
		len_color --;
	while (i < 6 && point_char[1][len_color - 1] != 'x'
			&& point_char[1][len_color - 1] != 'X')
	{
		(*point).color += (ft_power(16,
					i) * ft_obtain_color_hex(point_char[1][len_color - 1]));
		len_color --;
		i ++;
	}
}

void	ft_control_colors(t_point_map **map)
{
	int	color;
	int	y;
	int	x;

	color = 0;
	y = 0;
	while (map[y] && !color)
	{
		x = 0;
		while (x < map[y]->array_length)
		{
			if (map[y][x].color != COLOR_DEFAULT)
				color = 1;
			x ++;
		}
		y ++;
	}
	if (!color)
		ft_asign_colors_aux(map);
}
