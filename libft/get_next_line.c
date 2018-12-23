/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:19:43 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/12 20:04:09 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		length(char *s)
{
	int		length;

	length = 0;
	if (!s)
		return (0);
	while (s[length] != '\0' && s[length] != '\n')
		length++;
	return (length);
}

static char		*set_line(t_gnl **tmp)
{
	int		len;
	t_gnl	*lst;
	char	*var;
	char	*line;

	lst = *tmp;
	len = length(lst->data);
	line = NULL;
	if (END_IS_ENDL(lst->data[len]))
	{
		line = ft_strsub(lst->data, 0, len);
		var = ft_strdup(lst->data + len + 1);
		free(lst->data);
		lst->data = var;
		if (END_IS_NULL(lst->data[0]))
			ft_strdel(&lst->data);
		return (line);
	}
	if (END_IS_NULL(lst->data[len]))
	{
		line = ft_strdup(lst->data);
		ft_strdel(&lst->data);
		return (line);
	}
	return (line);
}

static t_gnl	*lst_new(int fd)
{
	t_gnl	*new_lst;

	new_lst = (t_gnl *)malloc(sizeof(t_list));
	if (new_lst)
	{
		new_lst->data = ft_strnew(1);
		new_lst->fd = fd;
		new_lst->next = NULL;
	}
	return (new_lst);
}

static t_gnl	*find_elem(int fd, t_gnl **lst)
{
	t_gnl	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = lst_new(fd);
	tmp->next = *lst;
	*lst = tmp;
	tmp = *lst;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;
	char			buffer[BUFF_SIZE + 1];
	t_gnl			*curr_fd;
	char			*tmp;
	int				read_bytes;

	if (CHECK_ERRORS(fd, line, buffer))
		return (ERROR);
	curr_fd = find_elem(fd, &lst);
	if (curr_fd->data == NULL)
		curr_fd->data = ft_strnew(1);
	while ((read_bytes = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[read_bytes] = '\0';
		tmp = ft_strjoin(curr_fd->data, buffer);
		free(curr_fd->data);
		curr_fd->data = tmp;
		if (ft_strchr(buffer, '\n'))
			STOP_READING;
	}
	if (CHECK_IF_EXIT(curr_fd->data, curr_fd->data[0], read_bytes))
		return (SUCCESS_END);
	*line = set_line(&curr_fd);
	return (1);
}
