/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:45:16 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/18 17:09:59 by nbiron           ###   ########.fr       */
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
	while(strr && strr[i] != '\n')
		i++;
	value = (char *)malloc(sizeof(char) * (i++));
	while (strr && strr[i])
	{
		str[a] = strr[i];
		i++;
		a++;
	}
	while (str[a])
		str[a++] = '\0';
	i = 0;
	while(strr && strr[i] != '\n')
	{
		value[i] = strr[i];
		i++;
	}
	value[i] = '\0';
	if (strr)
		free(strr);
	return (value);
}

#include <stdio.h>

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE];
	static char str[BUFFER_SIZE];
	char		*strr;

	if (fd <= 0)
		return (NULL);
	strr = (char *)malloc(sizeof(char) * 1);
	strr[0] = '\0';
	adds(strr, str);
	while (!strchr(strr, '\n'))
	{
		read(fd, buffer, BUFFER_SIZE);
		strr = adds(strr, buffer);
		printf("%s", strr);
	}
	strr = to_static(str, strr);
	return(strr);
}
