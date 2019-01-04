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

int				main(int argc, char *argv[])
{
	SDL_Window		*window;
	SDL_Renderer	*ren;
	SDL_Texture		*tex;
	Mix_Music		*music;
	t_frame			*f;

	if (argc != 2)
		error(3);
	play_music((music = NULL));
	f = setup_frame(argv[1], &window, &ren, &tex);
	frame_update_loop(ren, tex, f);
	free_everything(f, window, music, ren);
	return (0);
}
