/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:15:56 by OrioPrisc         #+#    #+#             */
/*   Updated: 2022/11/12 16:53:37 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	return (s);
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
bool	ft_strjoin_overflow(char **previous, char *buffer)
{
	char	*str;
	char	*next;
	size_t	lprev;
	size_t	lbuff;

	next = strrchrnul(lbuff, '\n');
	lbuff = next - buffer;
	lprev = 0;
	if (previous)
	{
		lprev = ft_strlen(*previous);
		str = malloc(lprev + lbuff + 1);
		if (!str)
			return (0);
		ft_strlcpy(str, *previous, lprev + 1);
	}
	ft_strlcpy(str + lprev, buffer, lbuff + 1);
	ft_strlcpy(buffer, next);
	free(*previous);
	*previous = str;
	return (*next == '\n');
}
