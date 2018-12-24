/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:51:42 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/24 14:51:44 by mdovhopo         ###   ########.fr       */
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

int		deal_key(int key, void *param)
{
	t_win *win;
	double rotSpeed = 0.1;
	double moveSpeed = 0.1;

	win = (t_win *)param;
	if (key == 53)
	{
		del_texture(win->texture);
		exit(0);
	}
	else if (key == 13) // w
	{
		if (WorldMap[(int)(win->posX + win->dirX)][(int)(win->posY)] == 0)
			win->posX += win->dirX * moveSpeed;
		if (WorldMap[(int)(win->posX)][(int)(win->posY + win->dirY)] == 0)
			win->posY += win->dirY * moveSpeed;
		render(win);
	}
	else if (key == 1) // s
	{
		if (WorldMap[(int)(win->posX + win->dirX)][(int)(win->posY)] == 0)
			win->posX -= win->dirX * moveSpeed;
		if (WorldMap[(int)(win->posX)][(int)(win->posY + win->dirY)] == 0)
			win->posY -= win->dirY * moveSpeed;
		render(win);
	}
	else if (key == 2) // a
	{
		double oldDirX = win->dirX;
		win->dirX = win->dirX * cos(-rotSpeed) - win->dirY * sin(-rotSpeed);
		win->dirY = oldDirX * sin(-rotSpeed) + win->dirY * cos(-rotSpeed);
		double oldPlaneX = win->planeX;
		win->planeX = win->planeX * cos(-rotSpeed) - win->planeY * sin(-rotSpeed);
		win->planeY = oldPlaneX * sin(-rotSpeed) + win->planeY * cos(-rotSpeed);
		render(win);
	}
	else if (key == 0) // d
	{
		double oldDirX = win->dirX;
		win->dirX = win->dirX * cos(rotSpeed) - win->dirY * sin(rotSpeed);
		win->dirY = oldDirX * sin(rotSpeed) + win->dirY * cos(rotSpeed);
		double oldPlaneX = win->planeX;
		win->planeX = win->planeX * cos(rotSpeed) - win->planeY * sin(rotSpeed);
		win->planeY = oldPlaneX * sin(rotSpeed) + win->planeY * cos(rotSpeed);
		render(win);
	}
	else if (key == 15)
	{
		win->posX = 22;
		win->posY = 11.5;
		win->planeX = 0;
		win->planeY = 0.66;
		win->dirX = -1;
		win->dirY = 0;
		clear_img(win);
		render(win);
	}
	//mlx_string_put(win->mlx_ptr, win->win_ptr, 0, HEIGHT - 20, 0x00FFFF, ft_itoa(WorldMap[(int)(win->posX)][(int)(win->posY)]));
	//ft_putnbr(key);
	//ft_putchar('\n');
	return (0);
}
