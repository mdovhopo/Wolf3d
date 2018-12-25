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

# include "../libft/libft.h"
# include <SDL2/SDL.h>
# include <SDL_image.h>
# include <stdio.h>
# include <string.h>
# include <stdbool.h>
# include "map.h"
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define MAPWIDTH 24
# define MAPHEIGHT 24
# define TEXWIDTH 64
# define TEXHEIGHT 64

typedef struct	s_frame
{
	int			color;
	t_uint		**texture;
	double		posX;
	double		posY;
	double		planeX;
	double		planeY;
	double		dirX;
	double		dirY;
	double		mousePosX;
}				t_frame;

/*
void			render(t_win *win);
void			clear_img(t_win *win);
void			draw_map(t_win *win, int posX, int posY);
//t_win			*setup(char *name);
int				ft_color_rgb(int r, int g, int b);
void			line(t_intvec2 start, t_intvec2 end, t_win *win);
*/
/*
** listeners
*/

int				motion_mouse(int x, int y, void *param);
int				deal_key(int key, void *param);

/*
** junk cleaners
*/

void			del_texture(t_uint **texture);

/*
** setters
*/

t_frame			*setup_frame(void);
t_uint			**set_texture(void);

/*
** for events
*/

void			event_manager(SDL_Event event, t_frame *frame);

#endif /* WOLF3D_H */
