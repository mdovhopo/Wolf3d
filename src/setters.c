/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 15:35:11 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/23 15:35:28 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_win	*setup(char *name)
{
	t_win *win;

	win = (t_win *)malloc(sizeof(t_win));
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIDTH, HEIGHT, name);
	win->img_ptr = mlx_new_image(win->mlx_ptr, WIDTH, HEIGHT);
	win->bits_per_pixel = 4;
	win->size_line = HEIGHT;
	win->endian = 0;
	win->color = 0;
	win->posX = 12;
	win->posY = 12;
	win->planeX = 0;
	win->planeY = 0.66;
	win->dirX = -1;
	win->dirY = 0;
	win->mousePosX = WIDTH / 2;
	win->img = mlx_get_data_addr(win->img_ptr, &win->bits_per_pixel,
		&win->size_line, &win->endian);
	return (win);
}
