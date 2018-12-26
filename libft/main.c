/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/26 17:51:34 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/12/26 17:53:13 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

#include "libft.h"
#include <stdio.h>

int main(void)
{
	char *dst = "1234567890";
	char *src = "src";

	printf("dst: %s\nsrc: %s\n", dst, src);
	ft_show_binary((unsigned int)(*dst + 1));
	ft_bzero(dst, 9);
	printf("dst: %s\nsrc: %s\n", dst, src);
	//ft_memcpy(dst, src, 3);
	return (0);
}
