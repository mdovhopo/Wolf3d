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

t_uint			**set_texture(void)
{
	int		i;
	int		x;
	int		y;
	t_uint	**texture;

	i = -1;
	x = -1;
	texture = (t_uint **)ft_memalloc(sizeof(t_uint *) * 8);

	while (++i < 8)
		texture[i] = (t_uint *)ft_memalloc(TEXWIDTH * TEXHEIGHT * sizeof(t_uint));
	while (++x < TEXWIDTH)
	{
		y = -1;
		while (++y < TEXHEIGHT)
		{
			int xorcolor = (x * 256 / TEXWIDTH) ^ (y * 256 / TEXHEIGHT);
			int ycolor = y * 256 / TEXHEIGHT;
			int xycolor = y * 128 / TEXHEIGHT + x * 128 / TEXWIDTH;
			texture[0][TEXWIDTH * y + x] = 65536 * 254 * (x != y && x != TEXWIDTH - y); //flat red texture with black cross
    		texture[1][TEXWIDTH * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
   			texture[2][TEXWIDTH * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
    		texture[3][TEXWIDTH * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
    		texture[4][TEXWIDTH * y + x] = 256 * xorcolor; //xor green
    		texture[5][TEXWIDTH * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
    		//texture[5] = img->pixels;
    		texture[6][TEXWIDTH * y + x] = 65536 * ycolor; //red gradient
    		texture[7][TEXWIDTH * y + x] = 0xff0066;//pink texture 128 + 256 * 128 + 65536 * 128 - flat grey texture
		}
	}
	return (texture);
}

t_frame		*setup_frame(void)
{
	t_frame	*f;

	f = (t_frame *)malloc(sizeof(t_frame));
	f->texture = set_texture();
	f->color = 0x000000;
    f->posX = 22;
	f->posY = 11.5;
	f->planeX = 0;
	f->planeY = 0.66;
	f->dirX = -1;
	f->dirY = 0;
	return (f);
}
