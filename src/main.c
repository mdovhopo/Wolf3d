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

static int		catch_event(t_frame *f, int fps)
{
	SDL_Event event;

	while (SDL_PollEvent(&event))
	{
		if (QUIT_EVENT)
			return (0);
		else if (SDL_SCANCODE_SPACE == event.key.keysym.scancode &&
				SDL_KEYDOWN == event.type)
		{
			ft_putstr("FPS: ");
			ft_putnbr(fps);
			write(1, "\n", 1);
		}
		event_manager(event, f);
	}
	return (1);
}

/*
** clock.x - start clok clock.y - clock.y
*/

int				main(int argc, char *argv[])
{
	SDL_Window		*window;
	Mix_Music		*music;
	t_frame			*f;
	t_vec2			clock;
	int				curr_fps;

	if (argc != 2)
		error(3);
	curr_fps = 0;
	music = NULL;
	play_music(music);
	f = setup_frame(argv[1], &window);
	while (catch_event(f, curr_fps))
	{
		clock.x = SDL_GetTicks();
		if (f->scene == 1)
			engine(f);
		SDL_UpdateWindowSurface(window);
		clock.y = SDL_GetTicks() - clock.x;
		if (clock.y != 0)
			curr_fps = 1000 / clock.y;
	}
	free_everything(f, window, music);
	return (0);
}
