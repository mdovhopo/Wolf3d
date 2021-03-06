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

void	move_forward(t_frame *f)
{
	double	movex;
	double	movey;
	double	wall_x;
	double	wall_y;

	movex = f->posx + f->dirx * f->move_speed;
	movey = f->posy + f->diry * f->move_speed;
	if (f->posx < movex)
		wall_x = 0.1;
	else
		wall_x = -0.1;
	if (f->posy < movey)
		wall_y = 0.1;
	else
		wall_y = -0.1;
	if (movex < f->mapheight - 1.1 && movex > 1.1 &&
					(f->map)[(int)(movex + wall_x)][(int)(f->posy)] == 0)
		f->posx += f->dirx * f->move_speed;
	if (movey < f->mapwidth - 1.1 && movey > 1.1 &&
					(f->map)[(int)(f->posx)][(int)(movey + wall_y)] == 0)
		f->posy += f->diry * f->move_speed;
}

void	move_back(t_frame *f)
{
	double	movex;
	double	movey;
	double	wall_x;
	double	wall_y;

	movex = f->posx - f->dirx * f->move_speed;
	movey = f->posy - f->diry * f->move_speed;
	if (f->posx < movex)
		wall_x = 0.1;
	else
		wall_x = -0.1;
	if (f->posy < movey)
		wall_y = 0.1;
	else
		wall_y = -0.1;
	if (movex < f->mapheight - 1.1 && movex > 1.1 &&
					(f->map)[(int)(movex + wall_x)][(int)(f->posy)] == 0)
		f->posx -= f->dirx * f->move_speed;
	if (movey < f->mapwidth - 1.1 && movey > 1.1 &&
					(f->map)[(int)(f->posx)][(int)(movey + wall_y)] == 0)
		f->posy -= f->diry * f->move_speed;
}

void	move_left(t_frame *f)
{
	double	movex;
	double	movey;

	movex = f->posx + -f->diry * f->move_speed;
	movey = f->posy + f->dirx * f->move_speed;
	if (movex < f->mapheight - 1.1 && movex > 1.1 &&
					(f->map)[(int)(movey)][(int)(f->posy)] == 0)
		f->posx += -f->diry * f->move_speed;
	if (movey < f->mapwidth - 1.1 && movey > 1.1 &&
					(f->map)[(int)(f->posx)][(int)(movey)] == 0)
		f->posy += f->dirx * f->move_speed;
}

void	move_right(t_frame *f)
{
	double	movex;
	double	movey;

	movex = f->posx + f->diry * f->move_speed;
	movey = f->posy + -f->dirx * f->move_speed;
	if (movex < f->mapheight - 1.1 && movex > 1.1 &&
					(f->map)[(int)(movex)][(int)(f->posy)] == 0)
		f->posx += f->diry * f->move_speed;
	if (movey < f->mapwidth - 1.1 && movey > 1.1 &&
					(f->map)[(int)(f->posx)][(int)(movey)] == 0)
		f->posy += -f->dirx * f->move_speed;
}

void	move_camera(t_frame *f, int x)
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
