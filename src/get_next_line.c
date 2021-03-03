/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonte <mmonte@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 20:50:32 by mmonte            #+#    #+#             */
/*   Updated: 2021/03/03 16:53:31 by mmonte           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static	int		ft_lastline(char **line, char **saver, char **buf, int ret)
{
	char *ptr;
	char *tmp;

	if (ret)
	{
		ptr = ft_strchr(*saver, '\n');
		*ptr++ = '\0';
		tmp = ft_strdup(ptr);
	}
	else
		tmp = NULL;
	*line = ft_strdup(*saver);
	free(*saver);
	free(*buf);
	*saver = tmp;
	return (ret);
}

static	char	*ft_savecheck(char **saver, char **buf)
{
	char *tmp;

	tmp = NULL;
	if (!*saver)
		*saver = ft_strdup(*buf);
	else
	{
		tmp = ft_strjoin(*saver, *buf);
		free(*saver);
		*saver = tmp;
	}
	return (tmp);
}

int				get_next_line(int fd, char **line)
{
	char		*buf;
	int			rb;
	static char	*saver;

	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		if (!(buf = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (-1);
		while ((rb = read(fd, buf, BUFFER_SIZE)) >= 0)
		{
			buf[rb] = '\0';
			ft_savecheck(&saver, &buf);
			if (ft_strchr(saver, '\n'))
				return (ft_lastline(line, &saver, &buf, 1));
			if (rb == 0)
				return (ft_lastline(line, &saver, &buf, 0));
		}
	}
	return (-1);
}
