/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:45:16 by nbiron            #+#    #+#             */
/*   Updated: 2023/11/01 13:32:39 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_static2(char str[BUFFER_SIZE], char *strr, int a, char *value)
{
	int	i;

	i = 0;
	while (str[a])
		str[a++] = '\0';
	while (strr && strr[i] && strr[i] != '\n')
	{
		value[i] = strr[i];
		i++;
	}
	if (strr[i] == '\n')
	{
		value[i] = '\n';
		i++;
	}
	value[i] = '\0';
	if (strr)
		free(strr);
	return (value);
}

char	*to_static(char str[BUFFER_SIZE], char *strr)
{
	int		i;
	int		a;
	char	*value;

	a = 0;
	i = 0;
	if (ft_strlen(strr) == 0)
		return (NULL);
	while (strr && strr[i] != '\n' && strr[i])
		i++;
	value = (char *)malloc(sizeof(char) * (i + 2));
	if (strr[i])
		i++;
	if (strr[i])
	{
		while (strr && strr[i])
		{
			str[a] = strr[i];
			i++;
			a++;
		}
	}
	return (to_static2(str, strr, a, value));
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char	static_str[BUFFER_SIZE];
	char		*strr;
	int			readsize;

	readsize = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buffer, 0) < 0)
		return (NULL);
	strr = adds(NULL, static_str, BUFFER_SIZE);
	while (!ft_strchr(strr, '\n') && readsize > 0 && strr)
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		strr = adds(strr, buffer, readsize);
	}
	//strr = to_static(static_str, strr);
	return (to_static(static_str, strr));
}
