/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_values.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 15:55:54 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/01/04 15:55:55 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		reset_values(t_frame *f)
{
	f->posx = f->defaultspawn_y;
	f->posy = f->defaultspawn_x;
	f->planex = 0.472722;
	f->planey = -0.460580;
	f->dirx = 0.697848;
	f->diry = 0.716246;
	f->move_speed = 0.1;
}
