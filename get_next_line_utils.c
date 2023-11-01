/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:45:18 by nbiron            #+#    #+#             */
/*   Updated: 2023/11/01 13:17:18 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	*ft_memcpy(void *dest, const void *src, size_t n, int value)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if ((!dest && !src) || !src)
		return (NULL);
	while (i < n)
	{
		if (value >= 0)
			d[i] = value;
		else
			d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*adds(char *dest, char *src, int src_size)
{
	char	*str;
	size_t	len1;

	len1 = 0;
	if (dest)
		len1 = ft_strlen(dest);
	str = (char *)malloc((len1 + src_size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	*str = '\0';
	if (dest)
		ft_memcpy(str, dest, len1, -1);
	if (dest)
		free(dest);
	if (src_size != 0)
		ft_memcpy(str + len1, src, src_size, -1);
	str[len1 + src_size] = '\0';
	return (str);
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
