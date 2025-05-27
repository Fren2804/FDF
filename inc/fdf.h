/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-22 20:17:37 by franmore          #+#    #+#             */
/*   Updated: 2025-03-22 20:17:37 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <X11/Xlib.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# define WIDTH_DEFAULT 800
# define HEIGHT_DEFAULT 600
# define COLOR_DEFAULT 0xffffff
# define COLOR_HIGH 0xff0000
# define COLOR_LOW 0xaaff00
# ifndef COLORS
#  define COLORS 0
# endif
# define HEX_LOW "0123456789abcdef"
# define ANGLE 0.523599

typedef struct s_general
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_pixel;
	int		size_length;
	int		endian;
	int		width;
	int		height;
	int		rows;
	int		columns;
	int		iso;
	int		offx_iso;
	int		offy_iso;
	int		offx_no_iso;
	int		offy_no_iso;
	int		zoom;
	float	rotate_z;
}	t_general;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_point;

typedef struct s_point_map
{
	int	z;
	int	color;
	int	array_length;
	int	scale;
}	t_point_map;

typedef struct s_bonus_aux
{
	t_general	*general;
	t_point_map	**map;
}	t_bonus_aux;

t_point_map	**ft_obtain_map(int fd);
void		ft_free_map_point(t_point_map **map);
void		ft_free_map_char(char **map_char);
int			ft_obtain_color_hex(char hex);
void		ft_obtain_point_color(t_point_map *point, char	**point_char);
void		ft_scale(t_point_map **map);
void		ft_control_colors(t_point_map **map);
void		ft_asign_colors_aux(t_point_map **map);

int			ft_obtain_width_height(int *width, int *height);
void		ft_init_offset(t_general *general);
void		ft_draw_lines(t_general *general, t_point_map **map);
void		ft_draw_line(t_general *general, t_point point1, t_point point2);
//void		ft_draw_line(void *mlx, void *win, t_point point1, t_point point2);
void		ft_abajo_iso(t_general *general, t_point_map **map, int x, int y);
void		ft_derecha_iso(t_general *general, t_point_map **map, int x, int y);
void		ft_abajo_no_iso(t_general *general, t_point_map **map,
				int x, int y);
void		ft_derecha_no_iso(t_general *general, t_point_map **map,
				int x, int y);
int			ft_interpolate_color(int color1, int color2, float t);

int			ft_close_window(void *param);
int			ft_close_window_key(int keycode, void *param);

void		ft_keys(t_general *general, t_point_map **map);
void		ft_key_zoom(t_bonus_aux *bonus, int i);
void		ft_key_rotate(t_bonus_aux *bonus, int i);
void		ft_rotate_z(t_point *point, float angle);
void		ft_change_color(t_bonus_aux *bonus);
void 		my_mlx_pixel_put(t_general *gen, int x, int y, int color);
void		ft_new_image(t_bonus_aux *bonus);

#endif