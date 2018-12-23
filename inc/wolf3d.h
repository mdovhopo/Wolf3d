/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:28:33 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/20 18:28:34 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "mlx.h"
# include <stdio.h>
# include "../libft/libft.h"
# include "map.h"
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define MAPWIDTH 24
# define MAPHEIGHT 24

typedef struct	s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			color;
	int			posX;
	int 		posY;
	int			dirX;
	int			dirY;
}				t_win;

void			render(t_win *win);
void			clear_img(t_win *win);
void			draw_map(t_win *win, int posX, int posY);
t_win			*setup(char *name);
int				ft_color_rgb(int r, int g, int b);
void			line(t_intvec2 start, t_intvec2 end, t_win *win);

#endif /* WOLF3D_H */
