/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_music.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 18:13:05 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/28 18:13:06 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			play_music(Mix_Music *music)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		ft_putendl("SDL_mixer could not initialize");
		exit(0);
	}
	if ((music = Mix_LoadMUS("music/main_theme.mp3")) == NULL)
	{
		ft_putendl("Music file not found");
		exit(0);
	}
	Mix_PlayMusic(music, -1);
}
