/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:15:56 by OrioPrisc         #+#    #+#             */
/*   Updated: 2022/11/12 16:53:37 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*ft_strchrnul(const char *s, char c)
{
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return ((char *)s);
}

size_t	ft_strlen(const char *c)
{
	size_t	len;

	len = 0;
	while (*c++)
		len++;
	return (len);
}

//joins *previous and buffer into previous up until a \n.
//Things after the \n gets copied into buffer
//returns wether a \n was seen
int	ft_strjoin_overflow(char **previous, char *buffer)
{
	char	*str;
	char	*next;
	size_t	lprev;
	size_t	lbuff;
	int		next_is_newline;

	next = ft_strchrnul(buffer, '\n');
	next_is_newline = (*next == '\n');
	lbuff = next - buffer + next_is_newline;
	lprev = 0;
	if (*previous)
		lprev = ft_strlen(*previous);
	str = malloc(lprev + lbuff + 1);
	if (!str)
		return (0);
	if (*previous)
		ft_strlcpy(str, *previous, lprev + 1);
	ft_strlcpy(str + lprev, buffer, lbuff + 1);
	ft_strlcpy(buffer, next + next_is_newline, BUFFER_SIZE + 1);
	free(*previous);
	*previous = str;
	return (next_is_newline);
}

size_t	ft_strlcpy(char *dest, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while ((i < size - 1) && src[i])
		{
			dest[i] = src[i];
			src[i] = 0;
			i++;
		}
		dest[i] = 0;
	}
	return (ft_strlen(src));
}
