/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:45:18 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/18 17:07:35 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*adds(char *str, char *c)
{
	int		y;
	char	*strr;

	y = 0;
	while (str && str[y])
		y++;
	strr = (char *)malloc(sizeof(char) * (y + ft_strlen(c) + 1));
	strr[y + ft_strlen(c)] = '\0';
	ft_strlcpy(strr, str, y + 1);
	ft_strlcat(strr, c, (ft_strlen(strr) + ft_strlen(c) + 1));
	//printf("%s", strr);
	if (str != NULL)
		free(str);
	return (strr);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dest_lenght;
	size_t	src_lenght;

	src_lenght = ft_strlen(src);
	dest_lenght = ft_strlen(dst);
	i = 0;
	j = dest_lenght;
	if (dest_lenght < size -1 && size > 0)
	{
		while (src[i] && dest_lenght + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = 0;
	}
	if (dest_lenght >= size)
		dest_lenght = size;
	return (dest_lenght + src_lenght);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	i2;

	i = 0;
	i2 = 0;
	while (src && src[i] != '\0')
		i++;
	if (size > 0)
	{
		while (src && src[i2] != '\0' && i2 < size - 1)
		{
			dest[i2] = src[i2];
			i2++;
		}
		dest[i2] = '\0';
	}
	return (i);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while ((unsigned char)s[i] != (unsigned char)c && s[i])
		i++;
	if (s[i] || !c)
		return ((char *)s + i);
	return (NULL);
}