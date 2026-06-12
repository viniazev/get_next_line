/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 19:56:29 by vinida-s          #+#    #+#             */
/*   Updated: 2026/06/09 23:27:54 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*destine;
	const unsigned char	*source;

	if (!dest && !src)
		return (NULL);
	destine = (unsigned char *)dest;
	source = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destine[i] = source[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*catstr;
	int		len_s1;
	int		len_s2;

	if (!s2)
		return (free(s1), s1 = NULL, NULL);
	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (free(s1), s1 = NULL, NULL);
		s1[0] = '\0';
	}
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	catstr = malloc(len_s1 + len_s2 + 1);
	if (!catstr)
		return (free(s1), s1 = NULL, NULL);
	ft_memcpy(catstr, s1, len_s1);
	ft_memcpy(catstr + len_s1, s2, len_s2);
	catstr[len_s1 + len_s2] = '\0';
	return (free(s1), catstr);
}
