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

int worldMap[MAPWIDTH][MAPHEIGHT]=
{
{1, 1, 1, 1, 1},
{1, 0, 0, 0, 1},
{1, 0, 0, 0, 1},
{1, 0, 0, 0, 1},
{1, 1, 1, 1, 1}
};

void	set_pix(char *pix)
{
	int x, y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			((int *)pix)[y * WIDTH + x] = 0x00FFFF;
		}
	}
}

void	engine(char *pixels, t_frame *f)
{
	double posX = f->posX, posY = f->posY;
	double dirX = f->dirX, dirY = f->dirY;
	double planeX = f->planeX, planeY = f->planeY;

	printf("%f %f\n", posY, posX);
	printf("%f %f\n", dirY, dirX);
	printf("%f %f\n", planeY, planeX);

	for (int x = 0;x < WIDTH; x++)
	{
		double cameraX = 2 * x / (double)WIDTH - 1;
		double rayDirX = dirX + planeX * cameraX;
		double rayDirY = dirY + planeY * cameraX;

		int mapX = (int)posX;
		int mapY = (int)posY;
		
		double sideDistX;
		double sideDistY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - posY) * deltaDistY;
		}
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;
		int lineHeight = (int)(HEIGHT / perpWallDist);
		if (0 && lineHeight > HEIGHT + 1)
			lineHeight = HEIGHT;
		int drawStart = -lineHeight / 2 + HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + HEIGHT / 2;
		if (drawEnd >= HEIGHT || drawEnd < 0)
			drawEnd = HEIGHT - 1;
		int texNum = worldMap[mapX][mapY] - 1;
		double wallX;
		if (side == 0)
			wallX = posY + perpWallDist * rayDirY;
		else
			wallX = posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);
		int texX = (int)(wallX * (double)TEXWIDTH);
		if (side == 0 && rayDirX > 0)
			texX = TEXWIDTH - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = TEXWIDTH - texX - 1;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int d = y * 256 - HEIGHT * 128 + lineHeight * 128;
			int texY = ((d * TEXHEIGHT) / lineHeight) / 256;
			int color = ((int *)f->texture[texNum]->pixels)[TEXWIDTH * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711;
			((int *)pixels)[y * WIDTH + x] = color;
		}
		if (drawStart > 0)
		{
			for (int y = drawStart - 1; y >= 0; y--)
			{
				((int *)pixels)[y * WIDTH + x] = 0x00BFFF;
			}
		}
		if (drawEnd < HEIGHT - 1)
		{
			for (int y = drawEnd; y < HEIGHT; y++)
			{
				((int *)pixels)[y * WIDTH + x] = 0x808080;
			}
		}
	}
}

// TODO check leaks
// TODO Pers go out map when come close to max map h-w
// TODO menu
// TODO reading map from file

int 	main(int argc, char const *argv[])
{
	SDL_Window 		*window;
	SDL_Event 		event;
	SDL_Surface		*surface;
	t_frame 		*f;

	f = setup_frame();
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return (1);
	atexit(SDL_Quit);
	SDL_ShowCursor(SDL_DISABLE);
	window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	surface = SDL_GetWindowSurface(window);
	SDL_WarpMouseInWindow(window, WIDTH / 2, HEIGHT / 2);
	bool running = true;
	while (running)
	{
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
		engine(surface->pixels, f);
		SDL_UpdateWindowSurface(window);
	ft_bzero(surface->pixels, WIDTH * HEIGHT * sizeof(int));
	}
	//del_textures();
	SDL_FreeSurface(surface);
    SDL_Quit();
    //system("leaks wolf3d");
	return 0;
}
