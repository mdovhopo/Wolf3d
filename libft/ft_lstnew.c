/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 17:49:46 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/10/31 18:42:35 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_lst;

	new_lst = (t_list *)malloc(sizeof(t_list));
	if (new_lst)
	{
		if (content == NULL)
		{
			new_lst->content = NULL;
			new_lst->content_size = 0;
			new_lst->next = NULL;
		}
		else
		{
			new_lst->content = malloc(content_size);
			if (content == NULL)
			{
				free(new_lst);
				return (NULL);
			}
			ft_memcpy(new_lst->content, content, content_size);
			new_lst->content_size = content_size;
			new_lst->next = NULL;
		}
	}
	return (new_lst);
}
