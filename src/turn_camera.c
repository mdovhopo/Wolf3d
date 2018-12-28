/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:05:39 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/28 15:05:40 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	turn_left(t_frame *f)
{
	double	rot_angle;
	double	old_dir;
	double	old_plane_x;

	old_dir = f->dirx;
	rot_angle = -0.08;
	f->dirx = f->dirx * cos(-rot_angle) - f->diry * sin(-rot_angle);
	f->diry = old_dir * sin(-rot_angle) + f->diry * cos(-rot_angle);
	old_plane_x = f->planex;
	f->planex = f->planex * cos(-rot_angle) - f->planey * sin(-rot_angle);
	f->planey = old_plane_x * sin(-rot_angle) + f->planey * cos(-rot_angle);
}

void	turn_right(t_frame *f)
{
	double	rot_angle;
	double	old_dir;
	double	old_plane_x;

	old_dir = f->dirx;
	rot_angle = 0.08;
	f->dirx = f->dirx * cos(-rot_angle) - f->diry * sin(-rot_angle);
	f->diry = old_dir * sin(-rot_angle) + f->diry * cos(-rot_angle);
	old_plane_x = f->planex;
	f->planex = f->planex * cos(-rot_angle) - f->planey * sin(-rot_angle);
	f->planey = old_plane_x * sin(-rot_angle) + f->planey * cos(-rot_angle);
}
