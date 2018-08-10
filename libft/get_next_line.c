/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afesyk <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 19:01:35 by afesyk            #+#    #+#             */
/*   Updated: 2018/01/24 19:01:37 by afesyk           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		save_line(char **buff, char **rest)
{
	char	*tmp;

	tmp = ft_strchr(*rest, '\n');
	if (tmp)
	{
		*buff = ft_realloc((void*)buff, ft_strlen(*buff) + (tmp - *rest) + 1);
		ft_strncat(*buff + ft_strlen(*buff), *rest, tmp - *rest);
		ft_memmove((void*)*rest, (void*)(tmp + 1), ft_strlen(tmp));
		return (1);
	}
	*buff = ft_realloc((void*)buff, ft_strlen(*buff) + ft_strlen(*rest) + 1);
	*buff = ft_strcat(*buff, *rest);
	ft_bzero(*rest, BUFF_SIZE);
	return (0);
}

static int		read_line(int fd, char **rest, char **line)
{
	char	*buff;
	int		s;

	buff = ft_strnew(0);
	s = 0;
	if (*rest != NULL)
		s = save_line(&buff, rest);
	if (!*rest)
		*rest = ft_strnew(BUFF_SIZE);
	while (!s && (s = read(fd, *rest, BUFF_SIZE)))
		s = save_line(&buff, rest);
	if (!s)
		ft_strdel(rest);
	if (*buff)
		s = 1;
	*line = ft_strdup(buff);
	ft_strdel(&buff);
	return (s);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*file;
	t_file			*curr;
	int				retval;

	if (fd < 0 || !line || read(fd, NULL, 0) == -1)
		return (-1);
	curr = file;
	while (curr != NULL && curr->fd != fd)
		curr = curr->next;
	if (!curr)
	{
		if (!(curr = malloc(sizeof(t_file))))
			return (-1);
		curr->fd = fd;
		curr->rest = NULL;
		curr->next = file;
		file = curr;
	}
	retval = read_line(curr->fd, &curr->rest, line);
	return (retval);
}
