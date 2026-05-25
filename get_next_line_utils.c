/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:56:29 by vinida-s          #+#    #+#             */
/*   Updated: 2026/05/25 22:02:01 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}


char	*ft_strchr(const char *s, int c)
{
    if (!s)
        return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_size;
	size_t	src_size;

	i = 0;
	dst_size = ft_strlen(dst);
	src_size = ft_strlen(src);
	if (dst_size >= size)
		return (size + src_size);
	while (src[i] && (i + dst_size < size - 1))
	{
		dst[i + dst_size] = src[i];
		i++;
	}
	dst[i + dst_size] = '\0';
	return (dst_size + src_size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*catstr;
	size_t	lenstrs;

	if (!s1 || !s2)
		return (NULL);
	lenstrs = ft_strlen(s1) + ft_strlen(s2) + 1;
	catstr = malloc(lenstrs);
	if (!catstr)
		return (NULL);
	catstr[0] = '\0';
	ft_strlcat(catstr, s1, lenstrs);
	ft_strlcat(catstr, s2, lenstrs);
	return (catstr);
}
