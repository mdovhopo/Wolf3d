/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 16:16:25 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/01/04 16:16:26 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		set_sdl_color(SDL_Color *c, int r, int g, int b)
{
	c->r = r;
	c->b = b;
	c->g = g;
	c->a = 0;
}

void			set_menu(SDL_Renderer *ren, SDL_Texture **tex)
{
	SDL_Surface	*s;
	TTF_Font	*font;
	SDL_Color	c;

	*tex = NULL;
	if (TTF_Init() < 0)
	{
		ft_putendl("TTF could not initialize");
		return ;
	}
	if ((font = TTF_OpenFont("fonts/OpenSans-BoldItalic.ttf", 24)) == NULL)
	{
		ft_putendl("No font founded");
		TTF_Quit();
		return ;
	}
	set_sdl_color(&c, 0xFF, 0xFF, 0xFF);
	s = TTF_RenderText_Solid(font, "Wolfenshtein 3D", c);
	*tex = SDL_CreateTextureFromSurface(ren, s);
	SDL_FreeSurface(s);
	TTF_CloseFont(font);
}
