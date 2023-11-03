/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:45:16 by nbiron            #+#    #+#             */
/*   Updated: 2023/11/03 10:08:57 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line(char *static_str)
{
	int		i;
	char	*s;

	i = 0;
	if (!static_str[i])
		return (NULL);
	while (static_str[i] && static_str[i] != '\n')
		i++;
	s = (char *)malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (static_str[i] && static_str[i] != '\n')
	{
		s[i] = static_str[i];
		i++;
	}
	if (static_str[i] == '\n')
	{
		s[i] = static_str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*ft_save(char *static_str)
{
	int		i;
	int		c;
	char	*s;

	i = 0;
	while (static_str[i] && static_str[i] != '\n')
		i++;
	if (!static_str[i])
	{
		free(static_str);
		return (NULL);
	}
	s = (char *)malloc(sizeof(char) * (ft_strlen(static_str) - i + 1));
	if (!s)
		return (NULL);
	i++;
	c = 0;
	while (static_str[i])
		s[c++] = static_str[i++];
	s[c] = '\0';
	free(static_str);
	return (s);
}

char	*ft_read(int fd, char *save)
{
	char	*buff;
	int		readsize;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	readsize = 1;
	while (!ft_strchr(save, '\n') && readsize != 0)
	{
		readsize = read(fd, buff, BUFFER_SIZE);
		if (readsize == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readsize] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*static_str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	static_str = ft_read(fd, static_str);
	if (!static_str)
		return (NULL);
	line = ft_line(static_str);
	static_str = ft_save(static_str);
	return (line);
}
