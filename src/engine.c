/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:03:42 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/28 14:03:46 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		get_texture(t_frame *f)
{
	int tex;

	if ((f->map)[f->map_x][f->map_y] - 1 > 0)
		tex = (f->map)[f->map_x][f->map_y] - 2;
	else
		tex = AMOUNT_TEXTURES - 1;
	if (f->map_y > f->posy && f->side == 1 && f->map_y != f->mapwidth - 1)
		return (tex);
	if (f->map_x > f->posx && f->side == 0 && f->map_x != f->mapheight - 1)
		return (tex);
	return ((f->map)[f->map_x][f->map_y] - 1);
}

static void		draw_floor_and_skay(t_intvec2 draw, t_frame *f, int x)
{
	int y;

	if (draw.x > 0)
	{
		y = draw.x;
		while (--y > -1)
			((int *)f->pixels)[y * WIDTH + x] = SKY_COLOR;
	}
	if (draw.y < HEIGHT - 1)
	{
		y = draw.y - 1;
		while (++y < HEIGHT)
			((int *)f->pixels)[y * WIDTH + x] = FLOOR_COLOR;
	}
}

/*
** line_height_and_wall x - line_height y - wall
*/

static void		draw_wall(t_intvec2 draw, t_frame *f,
						int x, t_vec2 line_height_and_wall)
{
	int			color;
	t_intvec2	tex;
	int			y;
	int			d;
	int			tex_num;

	tex.x = (int)(line_height_and_wall.y * (double)TEXWIDTH);
	if (f->side == 0 && f->ray_dir_x > 0)
		tex.x = TEXWIDTH - tex.x - 1;
	if (f->side == 1 && f->ray_dir_y < 0)
		tex.x = TEXWIDTH - tex.x - 1;
	y = draw.x - 1;
	tex_num = get_texture(f);
	while (++y < draw.y)
	{
		d = y * 256 - HEIGHT * 128 + line_height_and_wall.x * 128;
		tex.y = ((d * TEXHEIGHT) / line_height_and_wall.x) / 256;
		color = ((int *)f->texture[tex_num]->pixels)[TEXWIDTH * tex.y + tex.x];
		if (f->side == 1)
			color = (color >> 1) & 8355711;
		((int *)f->pixels)[y * WIDTH + x] = color;
	}
}

/*
** draw x - start, y - end
*/

static void		draw_image(double dist_to_wall, t_frame *f, int x)
{
	t_intvec2	draw;
	t_vec2		line_height_and_wall;
	int			color;

	line_height_and_wall.x = (int)(HEIGHT / dist_to_wall);
	draw.x = -line_height_and_wall.x / 2 + HEIGHT / 2;
	if (draw.x < 0)
		draw.x = 0;
	draw.y = line_height_and_wall.x / 2 + HEIGHT / 2;
	if (draw.y >= HEIGHT || draw.y < 0)
		draw.y = HEIGHT - 1;
	if (f->side == 0)
		line_height_and_wall.y = f->posy + dist_to_wall * f->ray_dir_y;
	else
		line_height_and_wall.y = f->posx + dist_to_wall * f->ray_dir_x;
	line_height_and_wall.y -= floor(line_height_and_wall.y);
	draw_wall(draw, f, x, line_height_and_wall);
	draw_floor_and_skay(draw, f, x);
}

void			engine(t_frame *f)
{
	int		x;
	double	dist_to_wall;
	int		step_x;
	int		step_y;

	x = -1;
	while (++x < WIDTH)
	{
		f->camera = 2 * x / (double)WIDTH - 1;
		f->ray_dir_x = f->dirx + f->planex * f->camera;
		f->ray_dir_y = f->diry + f->planey * f->camera;
		f->map_x = (int)f->posx;
		f->map_y = (int)f->posy;
		f->side = ray_caster(f, &step_x, &step_y);
		if (f->side == 0)
			dist_to_wall =
				(f->map_x - f->posx + (1 - step_x) / 2) / f->ray_dir_x;
		else
			dist_to_wall =
				(f->map_y - f->posy + (1 - step_y) / 2) / f->ray_dir_y;
		draw_image(dist_to_wall, f, x);
	}
	mini_map(f);
}
