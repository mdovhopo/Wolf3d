/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 14:04:53 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/27 14:04:54 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			count_size(char *path, t_frame *f)
{
	int		fd;
	char	*line;

	f->mapheight = 0;
	if ((fd = open(path, O_RDONLY)) < 0)
		error(0);
	if (get_next_line(fd, &line) > 0 && *line != '\0')
	{
		f->mapwidth = ft_count_words(line, ' ');
		f->mapheight += 1;
		free(line);
	}
	else
		error(1);
	while (get_next_line(fd, &line) > 0)
	{
		if (*line != '\0')
			f->mapheight += 1;
		free(line);
	}
	close(fd);
}

static int			fill_map(char *line, t_frame *f, int y)
{
	int x;

	x = 0;
	while (*line)
	{
		if (x > f->mapwidth)
		{
			free_map(f->map, y + 1);
			error(2);
		}
		while (*line == ' ')
		{
			line++;
			if (!*line)
				return (x);
		}
		f->map[y][x++] = ft_atoi((char *)line);
		while (*line != ' ')
		{
			if (!*line)
				return (x);
			line++;
		}
	}
	return (x);
}

static void			check_borders(t_frame *f, int h, int w)
{
	int x;
	int y;

	y = -1;
	if (h > 45 || h < 2 || w > 45 || w < 2)
	{
		free_map(f->map, h);
		error(6);
	}
	while (++y < f->mapheight)
	{
		x = -1;
		while (++x < f->mapwidth)
		{
			if (x == 0 || y == 0 ||
					y == f->mapheight - 1 || x == f->mapwidth - 1)
			{
				if (f->map[y][x] < 1)
				{
					free_map(f->map, f->mapheight);
					error(4);
				}
			}
		}
	}
}

void				load_map(char *path, t_frame *f)
{
	int		fd;
	int		i;
	int		prev_length;
	char	*line;

	i = 0;
	count_size(path, f);
	f->map = (int **)malloc(sizeof(int *) * f->mapheight);
	fd = open(path, O_RDONLY);
	prev_length = f->mapwidth;
	while (get_next_line(fd, &line) > 0)
	{
		(f->map)[i] = (int *)malloc(sizeof(int) * f->mapwidth);
		if (fill_map(line, f, i++) != prev_length)
		{
			free(line);
			free_map(f->map, i);
			error(2);
		}
		free(line);
	}
	close(fd);
	check_borders(f, f->mapheight, f->mapwidth);
}
