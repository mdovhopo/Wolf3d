/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:57:56 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/28 14:57:57 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	move_up(t_frame *f)
{
	double	movex;
	double	movey;

	movex = f->posx + f->dirx * f->move_speed;
	movey = f->posy + f->diry * f->move_speed;
	if (movex < f->mapheight - 1.2 && movex > 1.2 &&
					(f->map)[(int)(movex)][(int)(f->posy)] == 0)
		f->posx += f->dirx * f->move_speed;
	if (movey < f->mapwidth - 1.2 && movey > 1.2 &&
					(f->map)[(int)(f->posx)][(int)(movey)] == 0)
		f->posy += f->diry * f->move_speed;
}

void	move_back(t_frame *f)
{
	double	movex;
	double	movey;

	movex = f->posx - f->dirx * f->move_speed;
	movey = f->posy - f->diry * f->move_speed;
	if (movex < f->mapheight - 1.2 && movex > 1.2 &&
					(f->map)[(int)(movex)][(int)(f->posy)] == 0)
		f->posx -= f->dirx * f->move_speed;
	if (movey < f->mapwidth - 1.2 && movey > 1.2 &&
					(f->map)[(int)(f->posx)][(int)(movey)] == 0)
		f->posy -= f->diry * f->move_speed;
}

void	move_right(t_frame *f)
{
	double	movex;
	double	movey;

	movex = f->posx + -f->diry * f->move_speed;
	movey = f->posy + f->dirx * f->move_speed;
	if (movex < f->mapheight - 1.2 && movex > 1.2 &&
					(f->map)[(int)(movex)][(int)(f->posy)] == 0)
		f->posx += -f->diry * f->move_speed;
	if (movey < f->mapwidth - 1.2 && movey > 1.2 &&
					(f->map)[(int)(f->posx)][(int)(movey)] == 0)
		f->posy += f->dirx * f->move_speed;
}

void	move_left(t_frame *f)
{
	double	movex;
	double	movey;

	movex = f->posx + f->diry * f->move_speed;
	movey = f->posy + -f->dirx * f->move_speed;
	if (movex < f->mapheight - 1.2 && movex > 1.2 &&
					(f->map)[(int)(movex)][(int)(f->posy)] == 0)
		f->posx += f->diry * f->move_speed;
	if (movey < f->mapwidth - 1.2 && movey > 1.2 &&
					(f->map)[(int)(f->posx)][(int)(movey)] == 0)
		f->posy += -f->dirx * f->move_speed;
}

void	move_camera(t_frame *f, int x, int y)
{
	double	rot_angle;
	double	old_dir;
	double	old_plane_x;

	if (f->mouse_pos_x - x != 0)
	{
		rot_angle = f->mouse_pos_x - x > 0 ? -0.08 : 0.08;
		old_dir = f->dirx;
		f->dirx = f->dirx * cos(-rot_angle) - f->diry * sin(-rot_angle);
		f->diry = old_dir * sin(-rot_angle) + f->diry * cos(-rot_angle);
		old_plane_x = f->planex;
		f->planex = f->planex * cos(-rot_angle) - f->planey * sin(-rot_angle);
		f->planey = old_plane_x * sin(-rot_angle) + f->planey * cos(-rot_angle);
		f->mouse_pos_x = x;
	}
}
