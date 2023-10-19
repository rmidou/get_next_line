/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbiron <nbiron@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:45:13 by nbiron            #+#    #+#             */
/*   Updated: 2023/10/19 14:11:05 by nbiron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char 			*get_next_line(int fd);
char			*to_static(char str[BUFFER_SIZE], char *strr);
char			*adds(char *dest, char *src, int src_size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
int				ft_strlen(const char *str);
char			*ft_strchr(const char *s, int c);

#endif
