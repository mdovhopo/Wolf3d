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
{1, 1, 1, 1, 1},
{1, 0, 0, 0, 1},
{1, 0, 0, 0, 1},
{1, 0, 0, 0, 1},
{1, 1, 1, 1, 1}
};

double rotSpeed = 0.08;
double moveSpeed = 0.1;

static void	move_up(t_frame *f)
{
	if (WorldMap[(int)(f->posX + f->dirX * moveSpeed + 0.5)][(int)(f->posY)] == 0)
		f->posX += f->dirX * moveSpeed;
	if (WorldMap[(int)(f->posX)][(int)(f->posY + f->dirX * moveSpeed + 0.5)] == 0)
		f->posY += f->dirY * moveSpeed;
}

static void	move_back(t_frame *f)
{
	if (WorldMap[(int)(f->posX - f->dirX * moveSpeed - 0.5)][(int)(f->posY)] == 0)
		f->posX -= f->dirX * moveSpeed;
	if (WorldMap[(int)(f->posX)][(int)(f->posY - f->dirX * moveSpeed - 0.5)] == 0)
		f->posY -= f->dirY * moveSpeed;
}

static void	move_right(t_frame *f)
{
	double dirx;
	double tmp_dirx;
	double diry;

	dirx = -f->dirY * moveSpeed;
	diry = f->dirX * moveSpeed;
	if (WorldMap[(int)(f->posX + dirx + 0.5)][(int)(f->posY)] == 0)
		f->posX += dirx;
	if (WorldMap[(int)(f->posX)][(int)(f->posY + diry + 0.5)] == 0)
		f->posY += diry;
}

static void	move_left(t_frame *f)
{
	double dirx;
	double tmp_dirx;
	double diry;

	dirx = f->dirY * moveSpeed;
	diry = -f->dirX * moveSpeed;
	if (WorldMap[(int)(f->posX + dirx)][(int)(f->posY)] == 0)
		f->posX += dirx;
	if (WorldMap[(int)(f->posX)][(int)(f->posY + diry)] == 0)
		f->posY += diry;
}

static void	move_camera(t_frame *f, int x, int y)
{
	if (f->mousePosX - x != 0)
	{
		double rotAngle = f->mousePosX - x > 0 ? -rotSpeed : rotSpeed;
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
	f->posX = 1.5;
	f->posY = 1.5;
	f->planeX = 0.472722;
	f->planeY = -0.460580;
	f->dirX = 0.697848;
	f->dirY = 0.716246;
}

static void	infinite_rotate(int x, int y)
{
	int left_border;
	int right_border;
	int upper_border;
	int lower_border;

	upper_border = HEIGHT * 1 / 5;
	lower_border = HEIGHT * 4 / 5;	
	left_border = WIDTH * 1 / 5;
	right_border = WIDTH * 4 / 5;
	if (y >= lower_border)
		SDL_WarpMouseInWindow(NULL, x, upper_border + 1);
	else if (y <= upper_border)
		SDL_WarpMouseInWindow(NULL, x, lower_border - 1);
	if (x >= right_border)
		SDL_WarpMouseInWindow(NULL, left_border + 1, y);
	else if (x <= left_border)
		SDL_WarpMouseInWindow(NULL, right_border - 1, y);
}

static void	turn_left(t_frame *f)
{
	printf("left\n");
	double rotAngle = -rotSpeed;
	double oldDirX = f->dirX;
	f->dirX = f->dirX * cos(-rotAngle) - f->dirY * sin(-rotAngle);
	f->dirY = oldDirX * sin(-rotAngle) + f->dirY * cos(-rotAngle);
	double oldPlaneX = f->planeX;
	f->planeX = f->planeX * cos(-rotAngle) - f->planeY * sin(-rotAngle);
	f->planeY = oldPlaneX * sin(-rotAngle) + f->planeY * cos(-rotAngle);
}

static void turn_right(t_frame *f)
{
	printf("right\n");
	double rotAngle = rotSpeed;
	double oldDirX = f->dirX;
	f->dirX = f->dirX * cos(-rotAngle) - f->dirY * sin(-rotAngle);
	f->dirY = oldDirX * sin(-rotAngle) + f->dirY * cos(-rotAngle);
	double oldPlaneX = f->planeX;
	f->planeX = f->planeX * cos(-rotAngle) - f->planeY * sin(-rotAngle);
	f->planeY = oldPlaneX * sin(-rotAngle) + f->planeY * cos(-rotAngle);
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
			move_right(f);
		else if (SDL_SCANCODE_D == key_code)
			move_left(f);
		else if (SDL_SCANCODE_LEFT == key_code)
			turn_left(f);
		else if (SDL_SCANCODE_RIGHT == key_code)
			turn_right(f);
	}
	if (SDL_MOUSEMOTION == event.type)
	{
		infinite_rotate(event.motion.x, event.motion.y);
		move_camera(f, event.motion.x, event.motion.y);
	}
}
