/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: OrioPrisco <47635210+OrioPrisco@users      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:03:01 by OrioPrisc         #+#    #+#             */
/*   Updated: 2022/11/12 17:04:22 by OrioPrisc        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# define BUFFER_SIZE 100

char	*get_next_line(int fd);
char	*ft_strchrnul(const char *s, char c);
size_t	ft_strlen(const char *c);
int		ft_strjoin_overflow(char **previous, char *buffer);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

#endif
