/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 11:33:28 by franmore          #+#    #+#             */
/*   Updated: 2025-03-27 11:33:28 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_close_window(void *param)
{
	t_bonus_aux	*bonus;

	bonus = (t_bonus_aux *)param;
	ft_free_map_point(bonus->map);
	free(bonus);
	exit(0);
}

static void	ft_change_view(t_bonus_aux *bonus)
{
	bonus->general->iso = !bonus->general->iso;
	ft_new_image(bonus);
}

static void	ft_move(t_bonus_aux *bonus, int dir)
{
	if (dir == 0)
	{
		bonus->general->offx_iso -= 10;
		bonus->general->offx_no_iso -= 10;
	}
	if (dir == 2)
	{
		bonus->general->offx_iso += 10;
		bonus->general->offx_no_iso += 10;
	}
	if (dir == 1)
	{
		bonus->general->offy_iso += 10;
		bonus->general->offy_no_iso += 10;
	}
	if (dir == 3)
	{
		bonus->general->offy_iso -= 10;
		bonus->general->offy_no_iso -= 10;
	}
	ft_new_image(bonus);
}

static int	ft_keys_handle(int keycode, t_bonus_aux *bonus)
{
	if (keycode == 65307)
	{
		ft_close_window(bonus);
	}
	else if (keycode == 32)
		ft_change_view(bonus);
	else if (keycode == 65361)
		ft_move(bonus, 0);
	else if (keycode == 65362)
		ft_move(bonus, 1);
	else if (keycode == 65363)
		ft_move(bonus, 2);
	else if (keycode == 65364)
		ft_move(bonus, 3);
	else if (keycode == 61 || keycode == 65451)
		ft_key_zoom(bonus, 1);
	else if (keycode == 45 || keycode == 65453)
		ft_key_zoom(bonus, 0);
	else if (keycode == 113)
		ft_key_rotate(bonus, 1);
	else if (keycode == 101)
		ft_key_rotate(bonus, 0);
	else if (keycode == 99)
		ft_change_color(bonus);
	return (0);
}

void	ft_keys(t_general *general, t_point_map **map)
{
	t_bonus_aux	*bonus;

	bonus = malloc(sizeof(t_bonus_aux));
	bonus->general = general;
	bonus->map = map;
	mlx_hook(general->win, 2, 1L << 0, ft_keys_handle, bonus);
	mlx_hook(general->win, 17, 0, ft_close_window, bonus);
}
