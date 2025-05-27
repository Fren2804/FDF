/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-27 11:11:08 by franmore          #+#    #+#             */
/*   Updated: 2025-03-27 11:11:08 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_obtain_width_height(int *width, int *height)
{
	Display	*display;
	Screen	*screen;

	display = XOpenDisplay(NULL);
	if (display == NULL)
		return (1);
	screen = DefaultScreenOfDisplay(display);
	(*width) = (screen->width / 2) - 10;
	(*height) = screen->height - 31;
	XCloseDisplay(display);
	return (0);
}

void	ft_init_offset(t_general *general)
{
	general->iso = 1;
	general->offx_iso = 580;
	general->offy_iso = 215;
	general->offx_no_iso = 0;
	general->offy_no_iso = 0;
	general->zoom = 1;
	general->rotate_z = 0;
}
