/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:37:59 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/25 16:38:00 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			set_default_pos(t_frame *f)
{
	int x;
	int y;
	int flag;

	y = -1;
	flag = 0;
	while (++y < f->mapheight)
	{
		x = -1;
		while (++x < f->mapwidth)
		{
			if (flag == 0 && f->map[y][x] == 0)
			{
				f->defaultspawn_x = x + 0.5;
				f->defaultspawn_y = y + 0.5;
				flag = 1;
			}
			if (f->map[y][x] < 0 || f->map[y][x] > 6)
			{
				free_map(f->map, f->mapheight);
				error(4);
			}
		}
	}
}

static void			set_def_values(t_frame *f)
{
	f->minimapres = (WIDTH > HEIGHT ? HEIGHT / 6 : WIDTH / 6) /
			(f->mapheight > f->mapwidth ? f->mapwidth : f->mapheight);
	f->posx = f->defaultspawn_y;
	f->posy = f->defaultspawn_x;
	f->rotspeed = 0.08;
	f->movespeed = 0.1;
	f->planex = 0.472722;
	f->planey = -0.460580;
	f->dirx = 0.697848;
	f->diry = 0.716246;
	f->move_speed = 0.1;
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		ft_putendl("SDL could not initialize");
		free_map(f->map, f->mapheight);
		del_textures(f);
		exit(0);
	}
	atexit(SDL_Quit);
	SDL_ShowCursor(SDL_DISABLE);
}

static void			set_window(SDL_Window **window, t_frame *f)
{
	SDL_Surface		*surface;

	*window = SDL_CreateWindow("Wolf3D",
				SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED,
				WIDTH, HEIGHT,
				SDL_WINDOW_SHOWN);
	SDL_WarpMouseInWindow(*window, WIDTH / 2, HEIGHT / 2);
	surface = SDL_GetWindowSurface(*window);
	f->pixels = surface->pixels;
}

t_frame				*setup_frame(char *map_path,
				SDL_Window **window)
{
	t_frame	*f;

	f = (t_frame *)malloc(sizeof(t_frame));
	f->mapwidth = 0;
	load_map(map_path, f);
	f->defaultspawn_x = -1;
	f->defaultspawn_y = -1;
	set_default_pos(f);
	if (f->defaultspawn_x < 0 || f->defaultspawn_y < 0)
	{
		free_map(f->map, f->mapheight);
		error(5);
	}
	f->texture = load_texture();
	set_def_values(f);
	set_window(window, f);
	f->scene = 1;
	return (f);
}
