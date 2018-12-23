/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 17:23:58 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/01 19:17:38 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*lst;
	t_list	*ptr;

	if (*alst)
	{
		lst = *alst;
		while (lst)
		{
			ptr = lst->next;
			ft_lstdelone(&lst, del);
			lst = ptr;
		}
		*alst = NULL;
	}
}
