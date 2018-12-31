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

# include "libft/libft.h"
# include <SDL2/SDL.h>
# include <SDL_image.h>
# include <SDL_mixer.h>
# include <SDL_ttf.h>
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
# define SKY_COLOR 0x00BFFF
# define FLOOR_COLOR 0x696969

/*
** Defines for errors
*/

# define NO_FILE "No such file: "
# define USAGE "Usage: run ./wolf3d <map>"
# define NO_VALID_MAP "Map is not valid."
# define WRONG_LINE_LENGTH "Wrong line length."
# define WRONG_MAP_VALUE "Maps values must be between 0 and 6"
# define NO_ZEROS_ON_MAP "Map must have at least 1 zero"
# define TOO_BIG_MAP "Map is too big. max size: 45x45"

/*
** quit event
*/

# define TYPE_RED_CROSS SDL_QUIT == event.type
# define TYPE_ESC SDL_KEYDOWN == event.type
# define ESCAPE_PRESSED SDL_SCANCODE_ESCAPE == event.key.keysym.scancode
# define QUIT_EVENT (TYPE_RED_CROSS) || (TYPE_ESC && ESCAPE_PRESSED)

typedef struct	s_frame
{
	int			color;
	SDL_Surface	**texture;
	int			**map;
	int			mapheight;
	int			mapwidth;
	double		posx;
	double		posy;
	double		planex;
	double		planey;
	double		dirx;
	double		diry;
	double		mouse_pos_x;
	double		defaultspawn_x;
	double		defaultspawn_y;
	double		rotspeed;
	double		movespeed;
	int			minimapres;
	double		camera;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	char		*pixels;
	int			side;
	double		move_speed;
	int			scene;
}				t_frame;

/*
** drawing stuff
*/

void			mini_map(t_frame *f);
void			engine(t_frame *f);
int				ray_caster(t_frame *f, int *step_x, int *step_y);

/*
** listener
*/

void			event_manager(SDL_Event event, t_frame *frame);

/*
** junk cleaners
*/

void			del_textures(t_frame *f);
void			free_map(int **map, int i);

/*
** setters
*/

t_frame			*setup_frame(char *map_path,
				SDL_Window **window);
void			load_map(char *path, t_frame *f);
SDL_Surface		**load_texture(void);
void			play_music(Mix_Music *music);

/*
** moving / rotation camera
*/

void			move_up(t_frame *f);
void			move_back(t_frame *f);
void			move_right(t_frame *f);
void			move_left(t_frame *f);
void			move_camera(t_frame *f, int x);
void			turn_left(t_frame *f);
void			turn_right(t_frame *f);

/*
** error managment
*/

void			error(t_uint flag);

#endif
