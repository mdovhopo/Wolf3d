/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:10:16 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/28 14:10:17 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_vec2	find_side_dist(t_frame *f, int *step_x, int *step_y, t_vec2 delta_dist)
{
	t_vec2	side_dist;

	if (f->ray_dir_x < 0)
	{
		*step_x = -1;
		side_dist.x = (f->posx - f->map_x) * delta_dist.x;
	}
	else
	{
		*step_x = 1;
		side_dist.x = (f->map_x + 1.0 - f->posx) * delta_dist.x;
	}
	if (f->ray_dir_y < 0)
	{
		*step_y = -1;
		side_dist.y = (f->posy - f->map_y) * delta_dist.y;
	}
	else
	{
		*step_y = 1;
		side_dist.y = (f->map_y + 1.0 - f->posy) * delta_dist.y;
	}
	return (side_dist);
}

/*
** while loop is going until ray is not reached the wall
*/

int		ray_caster(t_frame *f, int *step_x, int *step_y)
{
	int		side;
	t_vec2	side_dist;
	t_vec2	delta_dist;

	delta_dist.x = fabs(1 / f->ray_dir_x);
	delta_dist.y = fabs(1 / f->ray_dir_y);
	side_dist = find_side_dist(f, step_x, step_y, delta_dist);
	while (1)
	{
		if (side_dist.x < side_dist.y)
		{
			side_dist.x += delta_dist.x;
			f->map_x += *step_x;
			side = 0;
		}
		else
		{
			side_dist.y += delta_dist.y;
			f->map_y += *step_y;
			side = 1;
		}
		if ((f->map)[f->map_x][f->map_y] > 0)
			break ;
	}
	return (side);
}
