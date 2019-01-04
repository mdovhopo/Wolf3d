/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_update_loop.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:05:16 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/01/04 16:05:17 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		catch_event(t_frame *f, int *if_event)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (QUIT_EVENT)
			return (0);
		event_manager(event, f);
		*if_event = 1;
	}
	return (1);
}

/*
** clock.x - start frame clock.y next frame
*/

static void		show_fps(t_vec2 clock, int flag, int *curr_fps)
{
	if (flag)
	{
		if (clock.y != 0)
			*curr_fps = 1000 / clock.y;
		ft_putstr("FPS: ");
		ft_putnbr(*curr_fps);
		write(1, "\n", 1);
	}
}

static void		update_renderer(SDL_Renderer *ren, t_frame *f,
		SDL_Texture *game_tex, SDL_Texture *menu_tex)
{
	SDL_Rect r;

	r.x = WIDTH / 2 - 200;
	r.y = HEIGHT / 2 - 200;
	r.w = 400;
	r.h = 100;
	SDL_RenderClear(ren);
	if (f->scene == GAME_SCENE)
	{
		engine(f);
		SDL_UpdateTexture(game_tex, NULL, (void *)(f->pixels), 1);
		SDL_RenderCopy(ren, game_tex, NULL, NULL);
	}
	else if (f->scene == MENU_SCENE)
	{
		SDL_RenderCopy(ren, menu_tex, NULL, &r);
	}
	SDL_RenderPresent(ren);
}

void			frame_update_loop(SDL_Renderer *ren, SDL_Texture *game_tex,
																	t_frame *f)
{
	SDL_Texture		*menu_tex;
	t_vec2			clock;
	int				if_event;
	int				curr_fps;

	curr_fps = 0;
	if_event = 1;
	set_menu(ren, &menu_tex);
	if (menu_tex != NULL)
	{
		while (catch_event(f, &if_event))
		{
			clock.x = SDL_GetTicks();
			if (if_event)
			{
				update_renderer(ren, f, game_tex, menu_tex);
				if_event = 0;
			}
			clock.y = SDL_GetTicks() - clock.x;
			show_fps(clock, f->fps_counter, &curr_fps);
		}
		SDL_DestroyTexture(menu_tex);
	}
	SDL_DestroyTexture(game_tex);
}
