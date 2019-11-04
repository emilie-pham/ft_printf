/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epham <epham@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 10:00:40 by anradix           #+#    #+#             */
/*   Updated: 2018/12/28 18:12:35 by epham            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

static char		*ft_save_line(char *files)
{
	if (ft_strchr(files, '\n'))
	{
		ft_strcpy(files, ft_strchr(files, '\n') + 1);
		return (files);
	}
	if (ft_word_len(files, '\n') > 0)
	{
		ft_strcpy(files, ft_strchr(files, '\0'));
		return (files);
	}
	return (NULL);
}

int				get_next_line(const int fd, char **line)
{
	static char		*files[1];
	char			*tmp;
	char			buf[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || BUFF_SIZE < 1 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!(files[fd]) && (files[fd] = ft_strnew(0)) == NULL)
		return (-1);
	while ((ft_strchr(files[fd], '\n') == 0)
		&& (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = files[fd];
		if (!(files[fd] = ft_strjoin(tmp, buf)))
			return (-1);
		free(tmp);
	}
	if (!(*line = ft_strsub(files[fd], 0, ft_word_len(files[fd], '\n') + 1)))
		return (-1);
	if (ft_save_line(files[fd]) == NULL)
		return (0);
	return (1);
}
