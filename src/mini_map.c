/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:00:09 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/28 14:00:10 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

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
			if ((int)f->posy == x && (int)f->posx == y)
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
