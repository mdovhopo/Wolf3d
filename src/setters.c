/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:37:59 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/25 16:38:00 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

SDL_Surface		*load_image(char *path)
{
	SDL_Surface 	*img;

	if ((img = IMG_Load(path)) == NULL)
	{
		ft_putstr(path);
		ft_putstr("\nImg not founded... \n");
		system("leaks wolf3d");
		exit(0);
	}
	return (img);
}

SDL_Surface		**load_texture(void)
{
	SDL_Surface	**texture;

	texture = (SDL_Surface **)ft_memalloc(sizeof(SDL_Surface **) * 8);
	printf("Loading textures...\n");
	texture[0] = load_image("pics/colorstone.png");
	texture[1] = load_image("pics/wood.png");
	texture[2] = load_image("pics/mossy.png");
	texture[3] = load_image("pics/redbrick.png");
	texture[4] = load_image("pics/greystone.png");
	texture[5] = load_image("pics/bluestone.png");
	texture[6] = load_image("pics/eagle.png");
	texture[7] = load_image("pics/purplestone.png");
	printf("Done!\n");
	return (texture);
}

void			set_default_pos(t_frame *f)
{
	int x;
	int y;
	int flag;

	y = -1;
	flag = 0;
	while (++y < f->mapheight)
	{
		x = -1;
		while (++x < f->mapwidth)
		{
			if (f->map[y][x] == 0 && flag == 0)
			{
				f->defaultspawn_x = x + 0.5;
				f->defaultspawn_y = y + 0.5;
				flag = 1;
			}
			if (f->map[y][x] < 0 || f->map[y][x] > 6)
			{
				free_map(f->map, f->mapheight);
				error(4);
			}
		}
	}
}

t_frame			*setup_frame(char *map_path)
{
	t_frame	*f;

	f = (t_frame *)malloc(sizeof(t_frame));
	f->mapwidth = 0;
	load_map(map_path, f);
	f->defaultspawn_x = -1;
	f->defaultspawn_y = -1;
	set_default_pos(f);
	if (f->defaultspawn_x < 0 || f->defaultspawn_y < 0)
	{
		free_map(f->map, f->mapheight);
		error(5);
	}
	f->texture = load_texture();
	f->minimapres = 200 /
			(f->mapheight > f->mapwidth ? f->mapwidth : f->mapheight);
	f->posX = f->defaultspawn_y;
	f->posY = f->defaultspawn_x;
	f->rotspeed = 0.08;
	f->movespeed = 0.1;
	f->planeX = 0.472722;
	f->planeY = -0.460580;
	f->dirX = 0.697848;
	f->dirY = 0.716246;
	return (f);
}
