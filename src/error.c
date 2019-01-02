/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 15:13:32 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/27 15:13:33 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			show_valid_map(void)
{
	ft_putendl("Valid map looks like this:");
	ft_putendl("1 1 1 1 1");
	ft_putendl("1 0 0 0 1");
	ft_putendl("1 0 2 0 1");
	ft_putendl("1 0 0 0 1");
	ft_putendl("1 1 1 1 1");
}

static void			error_2(t_uint flag)
{
	if (flag == 5)
	{
		ft_putendl(NO_ZEROS_ON_MAP);
		show_valid_map();
	}
	else if (flag == 6)
	{
		ft_putendl(TOO_BIG_MAP);
		show_valid_map();
	}
	else if (flag == 7)
		ft_putstr("\nImg not founded... \n");
	else if (flag == 8)
		ft_putendl("Music file not found");
}

void				error(t_uint flag)
{
	if (flag < 5)
	{
		if (flag == 0)
			ft_putendl(NO_FILE);
		else if (flag == 1)
		{
			ft_putendl(NO_VALID_MAP);
			show_valid_map();
		}
		else if (flag == 2)
		{
			ft_putendl(WRONG_LINE_LENGTH);
			show_valid_map();
		}
		else if (flag == 3)
			ft_putendl(USAGE);
		else if (flag == 4)
		{
			ft_putendl(WRONG_MAP_VALUE);
			show_valid_map();
		}
	}
	else
		error_2(flag);
	exit(0);
}
