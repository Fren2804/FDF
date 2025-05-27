/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-04-06 17:51:38 by franmore          #+#    #+#             */
/*   Updated: 2025-04-06 17:51:38 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_key_zoom(t_bonus_aux *bonus, int i)
{
	if (i)
		bonus->general->zoom += 1;
	else
	{
		bonus->general->zoom -= 1;
		if (bonus->general->zoom < 1)
			bonus->general->zoom = 1;
	}
	ft_new_image(bonus);
}

void	ft_key_rotate(t_bonus_aux *bonus, int i)
{
	if (i)
		bonus->general->rotate_z += 0.1;
	else
		bonus->general->rotate_z -= 0.1;
	ft_new_image(bonus);
}

void	ft_change_color(t_bonus_aux *bonus)
{
	ft_asign_colors_aux(bonus->map);
	ft_new_image(bonus);
}

void	ft_new_image(t_bonus_aux *bonus)
{
	t_general	*general;

	general = bonus->general;
	mlx_destroy_image(general->mlx, general->img);
	general->img = mlx_new_image(general->mlx, general->width, general->height);
	general->addr = mlx_get_data_addr(general->img, &general->bits_pixel,
			&general->size_length, &general->endian);
	ft_draw_lines(bonus->general, bonus->map);
}
