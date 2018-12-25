/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:48:39 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/25 16:48:40 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int WorldMap[MAPWIDTH][MAPHEIGHT]=
{
  {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,7,7,7,7,7,7,7,7},
  {4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7},
  {4,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,7},
  {4,0,4,0,0,0,0,5,5,5,5,5,5,5,5,5,7,7,0,7,7,7,7,7},
  {4,0,5,0,0,0,0,5,0,5,0,5,0,5,0,5,7,0,0,0,7,7,7,1},
  {4,0,6,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,7,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,7,7,1},
  {4,0,8,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,0,0,0,8},
  {4,0,0,0,0,0,0,5,0,0,0,0,0,0,0,5,7,0,0,0,7,7,7,1},
  {4,0,0,0,0,0,0,5,5,5,5,0,5,5,5,5,7,7,7,7,7,7,7,1},
  {6,6,6,6,6,6,6,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4},
  {6,6,6,6,6,6,0,6,6,6,6,0,6,6,6,6,6,6,6,6,6,6,6,6},
  {4,4,4,4,4,4,0,4,4,4,6,0,6,2,2,2,2,2,2,2,3,3,3,3},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,0,0,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,0,0,0,0,5,0,0,0,0,0,0,2},
  {4,0,0,5,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,2,0,2,2},
  {4,0,6,0,6,0,0,0,0,4,6,0,6,2,0,0,5,0,0,2,0,0,0,2},
  {4,0,0,0,0,0,0,0,0,4,6,0,6,2,0,0,0,0,0,2,0,0,0,2},
  {4,4,4,4,4,4,4,4,4,4,1,1,1,2,2,2,2,2,2,3,3,3,3,3}
};

double rotSpeed = 0.08;
double moveSpeed = 0.1;

static void	move_up(t_frame *f)
{
	if (WorldMap[(int)(f->posX + f->dirX * moveSpeed)][(int)(f->posY)] == 0)
		f->posX += f->dirX * moveSpeed;
	if (WorldMap[(int)(f->posX)][(int)(f->posY + f->dirX * moveSpeed)] == 0)
		f->posY += f->dirY * moveSpeed;
}

static void	move_back(t_frame *f)
{
	if (WorldMap[(int)(f->posX - f->dirX * moveSpeed)][(int)(f->posY)] == 0)
		f->posX -= f->dirX * moveSpeed;
	if (WorldMap[(int)(f->posX)][(int)(f->posY - f->dirX * moveSpeed)] == 0)
		f->posY -= f->dirY * moveSpeed;
}

static void	turn_right(t_frame *f)
{
	double oldDirX = f->dirX;
	f->dirX = f->dirX * cos(rotSpeed) - f->dirY * sin(rotSpeed);
	f->dirY = oldDirX * sin(rotSpeed) + f->dirY * cos(rotSpeed);
	double oldPlaneX = f->planeX;
	f->planeX = f->planeX * cos(rotSpeed) - f->planeY * sin(rotSpeed);
	f->planeY = oldPlaneX * sin(rotSpeed) + f->planeY * cos(rotSpeed);
}

static void	turn_left(t_frame *f)
{
	double oldDirX = f->dirX;
	f->dirX = f->dirX * cos(-rotSpeed) - f->dirY * sin(-rotSpeed);
	f->dirY = oldDirX * sin(-rotSpeed) + f->dirY * cos(-rotSpeed);
	double oldPlaneX = f->planeX;
	f->planeX = f->planeX * cos(-rotSpeed) - f->planeY * sin(-rotSpeed);
	f->planeY = oldPlaneX * sin(-rotSpeed) + f->planeY * cos(-rotSpeed);
}

static void	move_camera(t_frame *f, int x, int y)
{
	if (f->mousePosX - x != 0)
	{
		double rotAngle = f->mousePosX - x > 0 ? -0.1: 0.1;
		double oldDirX = f->dirX;
		f->dirX = f->dirX * cos(-rotAngle) - f->dirY * sin(-rotAngle);
		f->dirY = oldDirX * sin(-rotAngle) + f->dirY * cos(-rotAngle);
		double oldPlaneX = f->planeX;
		f->planeX = f->planeX * cos(-rotAngle) - f->planeY * sin(-rotAngle);
		f->planeY = oldPlaneX * sin(-rotAngle) + f->planeY * cos(-rotAngle);
		f->mousePosX = x;
	}
}

static void	reset_values(t_frame *f)
{
	f->posX = 22;
	f->posY = 11.5;
	f->planeX = 0;
	f->planeY = 0.66;
	f->dirX = -1;
	f->dirY = 0;
}

void		event_manager(SDL_Event event, t_frame *f)
{
	int key_code;

	key_code = event.key.keysym.scancode;
	if (SDL_KEYDOWN == event.type)
	{
		if (SDL_SCANCODE_W == key_code)
			move_up(f);
		else if (SDL_SCANCODE_S == key_code)
			move_back(f);
		else if (SDL_SCANCODE_R == key_code)
			reset_values(f);
		else if (SDL_SCANCODE_A == key_code)
			turn_right(f);
		else if (SDL_SCANCODE_D == key_code)
			turn_left(f);
	}
	if (SDL_MOUSEMOTION == event.type)
	{
		if (event.motion.x >= WIDTH - 5)
			SDL_WarpMouseInWindow(NULL, 10, event.motion.y);
		else if (event.motion.x <= 5)
			SDL_WarpMouseInWindow(NULL, WIDTH - 10, event.motion.y);
		move_camera(f, event.motion.x, event.motion.y);
	}
}
