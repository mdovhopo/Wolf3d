/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:36:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/25 16:36:44 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		free_everything(t_frame *f,
						SDL_Window *window, Mix_Music *music)
{
	del_textures(f);
	Mix_FreeMusic(music);
	free_map(f->map, f->mapheight);
	SDL_DestroyWindow(window);
	Mix_Quit();
	SDL_Quit();
}

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

static void		frame_update_loop(SDL_Window *window, t_frame *f)
{
	t_vec2			clock;
	int				if_event;
	int				curr_fps;

	curr_fps = 0;
	if_event = 1;
	while (catch_event(f, &if_event))
	{
		clock.x = SDL_GetTicks();
		if (if_event)
		{
			engine(f);
			SDL_UpdateWindowSurface(window);
			if_event = 0;
		}
		clock.y = SDL_GetTicks() - clock.x;
		show_fps(clock, f->fps_counter, &curr_fps);
	}
}

int				main(int argc, char *argv[])
{
	SDL_Window		*window;
	Mix_Music		*music;
	t_frame			*f;

	if (argc != 2)
		error(3);
	music = NULL;
	play_music(music);
	f = setup_frame(argv[1], &window);
	frame_update_loop(window, f);
	free_everything(f, window, music);
	return (0);
}
