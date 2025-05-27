/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 11:03:58 by franmore          #+#    #+#             */
/*   Updated: 2025-03-27 11:03:58 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

static int	ft_errors(int argc, char *argv[])
{
	int	fd;

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	return (fd);
}

static int	ft_erros_columns(t_point_map **map, t_general *general)
{
	int	i;
	int	column;

	i = 0;
	column = map[0][0].array_length;
	while (map[i])
	{
		if (column != map[i][0].array_length)
		{
			write(2, "Error, columns different size.\n", 31);
			ft_free_map_point(map);
			return (1);
		}
		i ++;
	}
	(*general).columns = column;
	(*general).rows = i;
	return (0);
}

static void	ft_main_aux(t_general general, t_point_map **map)
{
	ft_init_offset(&general);
	general.win = mlx_new_window(general.mlx, general.width,
			general.height, "FDF Francisco");
	general.img = mlx_new_image(general.mlx, general.width, general.height);
	general.addr = mlx_get_data_addr(general.img, &general.bits_pixel,
			&general.size_length, &general.endian);
	ft_draw_lines(&general, map);
	ft_keys(&general, map);
	mlx_loop(general.mlx);
	ft_free_map_point(map);
}

int	main(int argc, char *argv[])
{
	t_point_map	**map;
	t_general	general;
	int			fd;

	fd = ft_errors(argc, argv);
	if (fd < 0)
		return (2);
	map = ft_obtain_map(fd);
	if (ft_erros_columns(map, &general))
		return (2);
	close(fd);
	general.mlx = mlx_init();
	if (ft_obtain_width_height(&general.width, &general.height))
	{
		general.width = WIDTH_DEFAULT;
		general.height = HEIGHT_DEFAULT;
	}
	ft_main_aux(general, map);
	return (0);
}
