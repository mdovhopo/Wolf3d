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
# include <stdbool.h>
# include <math.h>

# define WIDTH 1280
# define HEIGHT 720
# define INTERFACE_WIDTH 200
# define INTERFACE_HEIGHT 720
# define AMOUNT_TEXTURES 8
# define TEXWIDTH 64
# define TEXHEIGHT 64

/*
** Defines for errors
*/

# define NO_FILE "No such file: "
# define USAGE "Usage: run ./wolf3d <map>"
# define NO_VALID_MAP "Map is not valid."
# define WRONG_LINE_LENGTH "Wrong line lenght."
# define WRONG_MAP_VALUE "Maps values must be between 0 and 6"
# define NO_ZEROS_ON_MAP "Map must have at least 1 zero"

typedef struct	s_frame
{
	int			color;
	SDL_Surface	**texture;
	int 		**map;
	int 		mapheight;
	int 		mapwidth;
	double		posX;
	double		posY;
	double		planeX;
	double		planeY;
	double		dirX;
	double		dirY;
	double		mousePosX;
	double		defaultspawn_x;
	double		defaultspawn_y;
	double		rotspeed;
	double		movespeed;
	int 		minimapres;
	double		camera;
	double		ray_dir_x;
	double 		ray_dir_y;
	int 		map_x;
	int 		map_y;
	char		*pixels;
	int 		side;
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

void			del_textures(t_frame *f);
void			free_map(int **map, int i);

/*
** setters
*/

t_frame			*setup_frame(char *map_path);
void			load_map(char *path, t_frame *f);

/*
** for events
*/

void			event_manager(SDL_Event event, t_frame *frame);

/*
** error managment
*/

void			error(t_uint flag);

#endif /* WOLF3D_H */
