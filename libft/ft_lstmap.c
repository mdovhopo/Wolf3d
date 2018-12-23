/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlambert <rlambert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 17:30:12 by rlambert          #+#    #+#             */
/*   Updated: 2018/11/07 15:32:47 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
	t_list	*first;
	t_list	*prev;

	if (!lst || !f)
		return (NULL);
	first = f(lst);
	prev = first;
	lst = lst->next;
	while (lst)
	{
		prev->next = f(lst);
		prev = prev->next;
		lst = lst->next;
	}
	return (first);
}
