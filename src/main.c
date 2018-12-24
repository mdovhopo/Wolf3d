/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 18:28:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/20 18:28:44 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		exit_hook(void *param)
{
	t_win *win;

	win = (t_win *)param;
	del_texture(win->texture);
	exit(0);
}

// TODO load map from comand line, map will store in fdf-like format
// let source code support SDL2  

int		main(int argc, char const *argv[])
{
	t_win		*win;

	win = setup("Wolf3d");
	render(win);
	mlx_hook(win->win_ptr, 2, 0, deal_key, (void *)win);
	mlx_hook(win->win_ptr, 17, 0, exit_hook, (void *)win);
	mlx_hook(win->win_ptr, 6, 0, motion_mouse, (void *)win);
	mlx_loop(win->mlx_ptr);
	return 0;
}
