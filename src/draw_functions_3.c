/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_functions_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 17:44:01 by franmore          #+#    #+#             */
/*   Updated: 2025-04-06 17:44:01 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static void	ft_project_iso(t_point *point)
{
	int	x;
	int	y;

	x = point->x;
	y = point->y;
	point->x = (x - y) * cos(ANGLE);
	point->y = (x + y) * sin(ANGLE) - point->z;
}

void	ft_derecha_iso(t_general *general, t_point_map **map, int x, int y)
{
	t_point	point1;
	t_point	point2;
	float	paso_x;
	float	paso_y;

	paso_x = (float)(general->width - (230 * 2)) / (general->columns - 1);
	paso_y = (float)(general->height - (230 * 2)) / (general->rows - 1);
	point1.x = (230 + (x * paso_x)) * general->zoom;
	point1.y = (230 + (y * paso_y)) * general->zoom;
	point1.z = (map[y][x].z * map[0]->scale) * general->zoom;
	point1.color = map[y][x].color;
	point2.x = (230 + ((x + 1) * paso_x)) * general->zoom;
	point2.y = (230 + (y * paso_y)) * general->zoom;
	point2.z = (map[y][x + 1].z * map[0]->scale) * general->zoom;
	point2.color = map[y][x + 1].color;
	ft_rotate_z(&point1, general->rotate_z);
	ft_rotate_z(&point2, general->rotate_z);
	ft_project_iso(&point1);
	ft_project_iso(&point2);
	point1.x += general->offx_iso;
	point1.y -= general->offy_iso;
	point2.x += general->offx_iso;
	point2.y -= general->offy_iso;
	ft_draw_line(general, point1, point2);
}

void	ft_abajo_iso(t_general *general, t_point_map **map, int x, int y)
{
	t_point	point1;
	t_point	point2;
	float	paso_x;
	float	paso_y;

	paso_x = (float)(general->width - (230 * 2)) / (general->columns - 1);
	paso_y = (float)(general->height - (230 * 2)) / (general->rows - 1);
	point1.x = (230 + (x * paso_x)) * general->zoom;
	point1.y = (230 + (y * paso_y)) * general->zoom;
	point1.z = (map[y][x].z * map[0]->scale) * general->zoom;
	point1.color = map[y][x].color;
	point2.x = (230 + (x * paso_x)) * general->zoom;
	point2.y = (230 + ((y + 1) * paso_y)) * general->zoom;
	point2.z = (map[y + 1][x].z * map[0]->scale) * general->zoom;
	point2.color = map[y + 1][x].color;
	ft_rotate_z(&point1, general->rotate_z);
	ft_rotate_z(&point2, general->rotate_z);
	ft_project_iso(&point1);
	ft_project_iso(&point2);
	point1.x += general->offx_iso;
	point1.y -= general->offy_iso;
	point2.x += general->offx_iso;
	point2.y -= general->offy_iso;
	ft_draw_line(general, point1, point2);
}

void	ft_derecha_no_iso(t_general *general, t_point_map **map, int x, int y)
{
	t_point	point1;
	t_point	point2;
	float	paso_x;
	float	paso_y;

	paso_x = (float)(general->width - (100 * 2)) / (general->columns - 1);
	paso_y = (float)(general->height - (100 * 2)) / (general->rows - 1);
	point1.x = (100 + (x * paso_x)) * general->zoom;
	point1.y = (100 + (y * paso_y)) * general->zoom;
	point1.color = map[y][x].color;
	point2.x = (100 + ((x + 1) * paso_x)) * general->zoom;
	point2.y = (100 + (y * paso_y)) * general->zoom;
	point2.color = map[y][x + 1].color;
	ft_rotate_z(&point1, general->rotate_z);
	ft_rotate_z(&point2, general->rotate_z);
	point1.x += general->offx_no_iso;
	point1.y -= general->offy_no_iso;
	point2.x += general->offx_no_iso;
	point2.y -= general->offy_no_iso;
	ft_draw_line(general, point1, point2);
}

void	ft_abajo_no_iso(t_general *general, t_point_map **map, int x, int y)
{
	t_point	point1;
	t_point	point2;
	float	paso_x;
	float	paso_y;

	paso_x = (float)(general->width - (100 * 2)) / (general->columns - 1);
	paso_y = (float)(general->height - (100 * 2)) / (general->rows - 1);
	point1.x = (100 + (x * paso_x)) * general->zoom;
	point1.y = (100 + (y * paso_y)) * general->zoom;
	point1.color = map[y][x].color;
	point2.x = (100 + (x * paso_x)) * general->zoom;
	point2.y = (100 + ((y + 1) * paso_y)) * general->zoom;
	point2.color = map[y + 1][x].color;
	ft_rotate_z(&point1, general->rotate_z);
	ft_rotate_z(&point2, general->rotate_z);
	point1.x += general->offx_no_iso;
	point1.y -= general->offy_no_iso;
	point2.x += general->offx_no_iso;
	point2.y -= general->offy_no_iso;
	ft_draw_line(general, point1, point2);
}
