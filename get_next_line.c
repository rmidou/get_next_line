/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:45:16 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/19 14:10:49 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*to_static(char str[BUFFER_SIZE], char *strr)
{
	int		i;
	int		a;
	char	*value;

	a = 0;
	i = 0;
	if (ft_strlen(strr) == 0)
		return(NULL);
	while(strr && strr[i] != '\n' && strr[i] != '\0')
		i++;
	value = (char *)malloc(sizeof(char) * (i++));
	if (strr[i] != '\0')
	{
		while (strr && strr[i])
		{
			str[a] = strr[i];
			i++;
			a++;
		}
	}
	while (str[a])
		str[a++] = '\0';
	i = 0;
	while(strr && strr[i] != '\n' && strr[i] != '\0')
	{
		value[i] = strr[i];
		i++;
	}
	if (strr[i] == '\n')
		value[i++] = '\n';
	value[i] = '\0';
	if (strr)
		free(strr);
	return (value);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char static_str[BUFFER_SIZE];
	char		*strr;
	int			readsize;

	readsize = 1;
	if (fd <= 0)
		return (NULL);
	strr = adds(NULL, static_str, BUFFER_SIZE);
	while (!strchr(strr, '\n') && readsize)
	{
		readsize = read(fd, buffer, BUFFER_SIZE);
		if (readsize > 0)
			strr = adds(strr, buffer, readsize);
	}
	strr = to_static(static_str, strr);
	//printf("|||\nstatic %s \n||||", static_str);
	return(strr);
}