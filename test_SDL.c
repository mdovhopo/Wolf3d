/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_SDL.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/23 16:27:00 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/23 16:43:34 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <SDL2/SDL.h>
#include <stdio.h>

int		main(void)
{
	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		printf("SDL Error\n");
		return (1);
	}
	return (0);
}
