/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infinite_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 17:01:41 by mdovhopo          #+#    #+#             */
/*   Updated: 2019/01/02 17:01:43 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		infinite_rotate(int x, int y)
{
	int left_border;
	int right_border;
	int upper_border;
	int lower_border;

	upper_border = HEIGHT * 1 / 5;
	lower_border = HEIGHT * 4 / 5;
	left_border = WIDTH * 1 / 5;
	right_border = WIDTH * 4 / 5;
	if (y >= lower_border)
		SDL_WarpMouseInWindow(NULL, x, upper_border + 1);
	else if (y <= upper_border)
		SDL_WarpMouseInWindow(NULL, x, lower_border - 1);
	if (x >= right_border)
		SDL_WarpMouseInWindow(NULL, left_border + 1, y);
	else if (x <= left_border)
		SDL_WarpMouseInWindow(NULL, right_border - 1, y);
}
