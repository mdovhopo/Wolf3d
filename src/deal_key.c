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
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int		deal_key(int key, void *param)
{
	t_win *win;
	double rotSpeed = 0.1;

	win = (t_win *)param;
	printf("pos: x: %f y: %f\n", win->posX, win->posY);
	printf("plane: x: %f y: %f\n", win->planeX, win->planeY);
	printf("dir: x: %f y: %f\n", win->dirX, win->dirY);
	if (key == 53)
		exit(0);
	else if (key == 91) // 8 numpad
	{
		if (WorldMap[(int)(win->posX + win->dirX)][(int)(win->posY)] == 0)
			win->posX += win->dirX;
		if (WorldMap[(int)(win->posX)][(int)(win->posY + win->dirY)] == 0)
			win->posY += win->dirY;
		render(win);
	}
	else if (key == 84) // 2 numpad
	{
		if (WorldMap[(int)(win->posX + win->dirX)][(int)(win->posY)] == 0)
			win->posX -= win->dirX;
		if (WorldMap[(int)(win->posX)][(int)(win->posY + win->dirY)] == 0)
			win->posY -= win->dirY;
		render(win);
	}
	else if (key == 88) // 4 numpad
	{
		double oldDirX = win->dirX;
		win->dirX = win->dirX * cos(-rotSpeed) - win->dirY * sin(-rotSpeed);
		win->dirY = oldDirX * sin(-rotSpeed) + win->dirY * cos(-rotSpeed);
		double oldPlaneX = win->planeX;
		win->planeX = win->planeX * cos(-rotSpeed) - win->planeY * sin(-rotSpeed);
		win->planeY = oldPlaneX * sin(-rotSpeed) + win->planeY * cos(-rotSpeed);
		render(win);
	}
	else if (key == 86) // 6 numpad
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
		win->posX = 12;
		win->posY = 12;
		win->planeX = 0;
		win->planeY = 0.66;
		win->dirX = -1;
		win->dirY = 0;
		clear_img(win);
		draw_map(win, win->posX, win->posY);
		render(win);
	}
	mlx_string_put(win->mlx_ptr, win->win_ptr, 0, HEIGHT - 20, 0x00FFFF, ft_itoa(WorldMap[(int)(win->posX)][(int)(win->posY)]));
	ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}
