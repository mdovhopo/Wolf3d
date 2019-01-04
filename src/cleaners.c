/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:30:59 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/27 15:31:11 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		free_map(int **map, int i)
{
	while (--i > -1)
		free(map[i]);
	free(map);
}

void		del_textures(t_frame *f)
{
	int i;

	i = AMOUNT_TEXTURES;
	while (--i > -1)
		SDL_FreeSurface(f->texture[i]);
	free(f->texture);
}

void		free_everything(t_frame *f,
		SDL_Window *window, Mix_Music *music, SDL_Renderer *ren)
{
	del_textures(f);
	Mix_FreeMusic(music);
	free_map(f->map, f->mapheight);
	free(f->pixels);
	SDL_DestroyRenderer(ren);
	SDL_DestroyWindow(window);
	free(f);
	Mix_Quit();
	SDL_Quit();
}
