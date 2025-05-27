/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_functions_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-28 11:17:49 by franmore          #+#    #+#             */
/*   Updated: 2025-03-28 11:17:49 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static char	**ft_obtain_map_char(int fd, int *row)
{
	char	**map_gnl;
	char	*gnl_read;

	(*row) = 0;
	map_gnl = NULL;
	gnl_read = get_next_line(fd);
	while (gnl_read)
	{
		map_gnl = realloc(map_gnl, ((*row) + 2) * sizeof(char *));
		if (!map_gnl)
		{
			perror("Error in memory asignation.");
			return (NULL);
		}
		map_gnl[(*row)] = ft_strdup(gnl_read);
		if (!map_gnl[(*row)])
			return (NULL);
		(*row)++;
		free(gnl_read);
		gnl_read = get_next_line(fd);
	}
	free(gnl_read);
	map_gnl[(*row)] = NULL;
	return (map_gnl);
}

static t_point_map	ft_obtain_point(char *split_point)
{
	t_point_map	point;
	char		**point_char;

	point_char = ft_split(split_point, ',');
	point.z = ft_atoi(point_char[0]);
	if (!point_char[1])
		point.color = COLOR_DEFAULT;
	else
		ft_obtain_point_color(&point, point_char);
	ft_free_map_char(point_char);
	return (point);
}

static t_point_map	*ft_obtain_array_points(char *map_char_one)
{
	t_point_map	*array;
	t_point_map	point;
	char		**split_points;
	int			i;

	split_points = ft_split(map_char_one, ' ');
	i = 0;
	while (split_points[i])
		i ++;
	array = malloc((i + 1) * sizeof(t_point_map));
	if (!array)
		return (NULL);
	i = 0;
	while (split_points[i])
	{
		point = ft_obtain_point(split_points[i]);
		array[i] = point;
		i ++;
	}
	ft_free_map_char(split_points);
	array[0].array_length = i;
	array[i].color = INT_MIN;
	return (array);
}

static t_point_map	**ft_obtain_map_points(char **map_char, int row)
{
	t_point_map	**map;
	t_point_map	*array;
	int			i;

	map = malloc((row + 1) * sizeof(t_point_map *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < row)
	{
		array = ft_obtain_array_points(map_char[i]);
		if (!array)
			return (NULL);
		map[i] = array;
		i ++;
	}
	map[i] = NULL;
	return (map);
}

t_point_map	**ft_obtain_map(int fd)
{
	t_point_map	**map;
	char		**map_char;
	int			row;

	map_char = ft_obtain_map_char(fd, &row);
	close (fd);
	if (!map_char)
		return (NULL);
	if (row < 2)
	{
		perror("Error. Few rows");
		return (NULL);
	}
	map = ft_obtain_map_points(map_char, row);
	ft_free_map_char(map_char);
	ft_control_colors(map);
	return (map);
}
