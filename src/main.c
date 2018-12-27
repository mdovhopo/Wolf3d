/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:36:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/25 16:36:44 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int 	get_texture(t_frame *f)
{
	int tex;

	if ((f->map)[f->map_x][f->map_y] - 1 > 0)
		tex = (f->map)[f->map_x][f->map_y] - 2;
	else
		tex = AMOUNT_TEXTURES - 1;
	if (f->map_y > f->posY && f->side == 1 && f->map_y != f->mapwidth - 1)
		return (tex);
	if (f->map_x > f->posX && f->side == 0 && f->map_x != f->mapheight - 1)
		return (tex);
	return ((f->map)[f->map_x][f->map_y] - 1);
}

void	rect(char *pix, t_intvec2 pos, t_frame *f, int color)
{
	int x1;
	int y1;

	y1 = -1;
	while (++y1 < f->minimapres)
	{
		x1 = -1;
		while (++x1 < f->minimapres)
			((int *)pix)[(pos.y + y1) * WIDTH + (pos.x + x1)] = color;
	}
}

void	mini_map(t_frame *f)
{
	int x;
	int y;
	int color;

	y = -1;
	color = 0x000000;
	while (++y < f->mapheight)
	{
		x = -1;
		while (++x < f->mapwidth)
		{
			if ((int)f->posY == x && (int)f->posX == y)
				color = 0x800000;
			else if (f->map[y][x] == 0)
				color = 0x00FFFF;
			else if (f->map[y][x] > 0)
				color = 0xFF0000;
			rect(f->pixels,
			ft_new_intvec2(x * f->minimapres, y * f->minimapres), f, color);
		}
	}
}
/*
void	f->side_dist(double *f->side_dist_x, double *f->side_dist_y)
{

}
*/
int 	ray_caster(t_frame *f, int *step_x, int *step_y)
{
	int 	side;
	int 	hit = 0;
	double	sideDistX;
	double	sideDistY;
	double	deltaDistX;
	double	deltaDistY;

	deltaDistX = fabs(1 / f->ray_dir_x);
	deltaDistY = fabs(1 / f->ray_dir_y);
	if (f->ray_dir_x < 0)
	{
		*step_x = -1;
		sideDistX = (f->posX - f->map_x) * deltaDistX;
	}
	else
	{
		*step_x = 1;
		sideDistX = (f->map_x + 1.0 - f->posX) * deltaDistX;
	}
	if (f->ray_dir_y < 0)
	{
		*step_y = -1;
		sideDistY = (f->posY - f->map_y) * deltaDistY;
	}
	else
	{
		*step_y = 1;
		sideDistY = (f->map_y + 1.0 - f->posY) * deltaDistY;
	}
	while (hit == 0)
	{
		if (sideDistX < sideDistY)
		{
		sideDistX += deltaDistX;
			f->map_x += *step_x;
			side = 0;
		}
		else
		{
			sideDistY += deltaDistY;
			f->map_y += *step_y;
			side = 1;
		}
		if ((f->map)[f->map_x][f->map_y] > 0)
			hit = 1;
	}
	return (side);
}

/*
** draw x - start, y - end
*/

void	draw_floor_skay(t_intvec2 draw, t_frame *f, int x)
{
	if (draw.x > 0)
	{
		for (int y = draw.x - 1; y >= 0; y--)
		{
			((int *)f->pixels)[y * WIDTH + x] = 0x00BFFF;
		}
	}
	if (draw.y < HEIGHT - 1)
	{
		for (int y = draw.y; y < HEIGHT; y++)
		{
			((int *)f->pixels)[y * WIDTH + x] = 0x696969;
		}
	}
}

/*
** line_height_and_wall x - line_height y - wall 
*/

void	draw_wall(t_intvec2 draw, t_frame *f, int x, t_vec2 line_height_and_wall)
{
	int 		color;
	t_intvec2	tex;

	tex.x = (int)(line_height_and_wall.y * (double)TEXWIDTH);
	if (f->side == 0 && f->ray_dir_x > 0)
		tex.x = TEXWIDTH - tex.x - 1;
	if (f->side == 1 && f->ray_dir_y < 0)
		tex.x = TEXWIDTH - tex.x - 1;
	for (int y = draw.x; y < draw.y; y++)
	{
		int d = y * 256 - HEIGHT * 128 + line_height_and_wall.x * 128;
		tex.y = ((d * TEXHEIGHT) / line_height_and_wall.x) / 256;
		color = ((int *)f->texture[get_texture(f)]->pixels)[TEXWIDTH * tex.y + tex.x];
		if (f->side == 1)
			color = (color >> 1) & 8355711;
		((int *)f->pixels)[y * WIDTH + x] = color;
	}
}

void	draw_image(double dist_to_wall, t_frame *f, int x)
{
	t_intvec2 	draw;
	t_vec2	line_height_and_wall;
	int 		color;

	line_height_and_wall.x = (int)(HEIGHT / dist_to_wall);
	draw.x = -line_height_and_wall.x / 2 + HEIGHT / 2;
	if (draw.x < 0)
		draw.x = 0;
	draw.y = line_height_and_wall.x / 2 + HEIGHT / 2;
	if (draw.y >= HEIGHT || draw.y < 0)
		draw.y = HEIGHT - 1;
	if (f->side == 0)
		line_height_and_wall.y = f->posY + dist_to_wall * f->ray_dir_y;
	else
		line_height_and_wall.y = f->posX + dist_to_wall * f->ray_dir_x;
	line_height_and_wall.y -= floor(line_height_and_wall.y);
	draw_wall(draw, f, x, line_height_and_wall);
	draw_floor_skay(draw, f, x);
}

void	engine(t_frame *f)
{
	int 	x;
	double 	dist_to_wall;
	int 	step_x;
	int 	step_y;

	x = -1;
	while (++x < WIDTH)
	{
		f->camera = 2 * x / (double)WIDTH - 1;
		f->ray_dir_x = f->dirX + f->planeX * f->camera;
		f->ray_dir_y = f->dirY + f->planeY * f->camera;
		f->map_x = (int)f->posX;
		f->map_y = (int)f->posY;
		f->side = ray_caster(f, &step_x, &step_y);
		if (f->side == 0)
			dist_to_wall = (f->map_x - f->posX + (1 - step_x) / 2) / f->ray_dir_x;
		else
			dist_to_wall = (f->map_y - f->posY + (1 - step_y) / 2) / f->ray_dir_y;
		draw_image(dist_to_wall, f, x);
	}
	mini_map(f);
}

// TODO check leaks
// TODO menu
// TODO NORME

int 	main(int argc, char *argv[])
{
	SDL_Window 		*window;
	SDL_Event 		event;
	SDL_Surface		*surface;
	t_frame 		*f;

	if (argc != 2)
		error(3);
	f = setup_frame(argv[1]);
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (1);
	atexit(SDL_Quit);
	SDL_ShowCursor(SDL_DISABLE);
	window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	SDL_WarpMouseInWindow(window, WIDTH / 2, HEIGHT / 2);
	bool running = true;
	int startclock = 0;
	int deltaclock = 0;
	int currFPS = 0;
	while (running)
	{
		startclock = SDL_GetTicks();
		while(SDL_PollEvent(&event))
		{
			if((SDL_QUIT == event.type) ||
				(SDL_KEYDOWN == event.type && SDL_SCANCODE_ESCAPE == event.key.keysym.scancode))
			{
				running = false;
				break;
			}
			event_manager(event, f);
		}
		f->pixels = surface->pixels;
		engine(f);
		SDL_UpdateWindowSurface(window);
		deltaclock = SDL_GetTicks() - startclock;
		startclock = SDL_GetTicks();

		if (deltaclock != 0)
			currFPS = 1000 / deltaclock;
		//ft_putnbr(currFPS);
		//write(1, "\n", 1);
	}
	del_textures(f);
	free_map(f->map, f->mapheight);
	SDL_FreeSurface(surface);
	SDL_Quit();
	//system("leaks wolf3d");
	return 0;
}
