/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:48:39 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/25 16:48:40 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		reset_values(t_frame *f)
{
	f->posx = f->defaultspawn_y;
	f->posy = f->defaultspawn_x;
	f->planex = 0.472722;
	f->planey = -0.460580;
	f->dirx = 0.697848;
	f->diry = 0.716246;
	f->move_speed = 0.1;
}

static void		fps_on_off(int *fps_counter)
{
	if (*fps_counter == 0)
		*fps_counter = 1;
	else
		*fps_counter = 0;
}

static void		key_down_event(t_frame *f, int key_code)
{
	if (SDL_SCANCODE_W == key_code || SDL_SCANCODE_UP == key_code)
		move_forward(f);
	else if (SDL_SCANCODE_S == key_code || SDL_SCANCODE_DOWN == key_code)
		move_back(f);
	else if (SDL_SCANCODE_R == key_code)
		reset_values(f);
	else if (SDL_SCANCODE_A == key_code)
		move_left(f);
	else if (SDL_SCANCODE_D == key_code)
		move_right(f);
	else if (SDL_SCANCODE_LEFT == key_code)
		turn_left(f);
	else if (SDL_SCANCODE_RIGHT == key_code)
		turn_right(f);
	else if (SDL_SCANCODE_F == key_code)
		fps_on_off(&(f->fps_counter));
}

static void		mouse_motion_event(t_frame *f, int x, int y)
{
	infinite_rotate(x, y);
	move_camera(f, x);
}

void			event_manager(SDL_Event event, t_frame *f)
{
	int key_code;

	printf("%f %f\n", f->posx, f->posy);
	key_code = event.key.keysym.scancode;
	if (SDL_KEYDOWN == event.type)
		key_down_event(f, key_code);
	else if (SDL_MOUSEMOTION == event.type)
		mouse_motion_event(f, event.motion.x, event.motion.y);
}
