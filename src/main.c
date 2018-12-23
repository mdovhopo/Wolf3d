/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:28:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/20 18:28:44 by mdovhopo         ###   ########.fr       */
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

void	character(t_win *win, int posX, int posY)
{
	int i;

	i = 10;
	while (--i > 0)
		((int *)win->img)[(posY * 5 - i) * WIDTH + (posX * 5)] = 0xFF0000;
}

void	draw_map(t_win *win, int posX, int posY)
{
	int color;

	for (int x = 0; x < MAPHEIGHT; x++)
		for (int y = 0; y < MAPWIDTH; y++)
		{
			switch (WorldMap[x][y])
			{
				case 1: color = ft_color_rgb(255, 0, 0); break;
				case 2: color = ft_color_rgb(0, 255, 0); break;
				case 3: color = ft_color_rgb(0, 0, 255); break;
				case 4: color = ft_color_rgb(255, 255, 255); break;
				default: color = ft_color_rgb(255, 255, 0); break;
			}
			if (x == posY && y == posY)
				character(win, posX, posY);
			else
				((int *)win->img)[(y * 5) * WIDTH + (x * 5)] = color;
		}

}

int		deal_key(int key, void *param)
{
	t_win *win;

	win = (t_win *)param;
	if (key == 53)
		exit(0);
	else if (key == 126)
	{
		printf("x: %i y: %i\n", win->posX, win->posY);
		int x = WorldMap[win->posX - 1][win->posY];
		if (win->posX > 2 && x == 0)
		{
			win->posX--;
			render(win);
		}
		mlx_string_put(win->mlx_ptr, win->win_ptr, 0, HEIGHT - 20, 0x00FFFF, ft_itoa(x));
		draw_map(win, win->posX, win->posY);
	}
	else if (key == 15)
	{
		win->posX = 22;
		win->posY = 12;
		clear_img(win);
		draw_map(win, win->posX, win->posY);
		render(win);
	}
	ft_putnbr(key);
	ft_putchar('\n');
	return (0);
}

int		exit_hook(void *param)
{
	exit(0);
}

int		main(int argc, char const *argv[])
{
	t_win		*win;

	int x = WorldMap[2][2];
	win = setup("Wolf3d");
	render(win);
	mlx_hook(win->win_ptr, 2, 0, deal_key, (void *)win);
	mlx_hook(win->win_ptr, 17, 0, exit_hook, (void *)win);
	mlx_loop(win->mlx_ptr);
	return 0;
}
