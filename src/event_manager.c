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

static void		fps_on_off(int *fps_counter)
{
	if (*fps_counter == 0)
		*fps_counter = 1;
	else
		*fps_counter = 0;
}

static void		change_scene(int *scene)
{
	if (*scene == MENU_SCENE)
	{
		SDL_ShowCursor(SDL_DISABLE);
		*scene = GAME_SCENE;
	}
	else
	{
		SDL_ShowCursor(SDL_ENABLE);
		*scene = MENU_SCENE;
	}
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
	else if (SDL_SCANCODE_SPACE == key_code)
		change_scene(&(f->scene));
}

static void		mouse_motion_event(t_frame *f, int x, int y)
{
	infinite_rotate(x, y);
	move_camera(f, x);
}

void			event_manager(SDL_Event event, t_frame *f)
{
	int key_code;

	key_code = event.key.keysym.scancode;
	if (f->scene == GAME_SCENE)
	{
		if (SDL_KEYDOWN == event.type)
			key_down_event(f, key_code);
		else if (SDL_MOUSEMOTION == event.type)
			mouse_motion_event(f, event.motion.x, event.motion.y);
	}
	else if (f->scene == MENU_SCENE)
	{
		if (SDL_KEYDOWN == event.type)
			change_scene(&(f->scene));
	}
}
