/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:36:36 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/28 15:36:37 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static SDL_Surface		*load_image(char *path)
{
	SDL_Surface	*img;

	if ((img = IMG_Load(path)) == NULL)
	{
		ft_putstr(path);
		error(7);
	}
	return (img);
}

SDL_Surface				**load_texture(void)
{
	SDL_Surface	**texture;

	texture = (SDL_Surface **)ft_memalloc(sizeof(SDL_Surface **) * 8);
	texture[0] = load_image("pics/colorstone.png");
	texture[1] = load_image("pics/wood.png");
	texture[2] = load_image("pics/mossy.png");
	texture[3] = load_image("pics/redbrick.png");
	texture[4] = load_image("pics/greystone.png");
	texture[5] = load_image("pics/bluestone.png");
	texture[6] = load_image("pics/eagle.png");
	texture[7] = load_image("pics/purplestone.png");
	return (texture);
}
