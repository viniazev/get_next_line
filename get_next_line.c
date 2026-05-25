/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 21:09:01 by vinida-s          #+#    #+#             */
/*   Updated: 2026/05/25 22:13:12 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char			*stash;
	static size_t	position;

	char *buffer; /*string de retorno*/
	/*string onde salvarei o que esta sendo lido pelo read*/
	/*bytes lidos pelo read??? provavelmente o static q eu necessito*/
	position = read(fd, stash, 10);
	while (position > 0 || position == 0)
	{
        stash = ft_strchr(stash, '\n');
		buffer = ft_strjoin(buffer, stash);
		position = read(fd, stash, 10);
	}
	// free (stash);
	return (buffer);
}

int	main(int argc, char **argv)
{
	int     file;
	char    *str;

	if (argc != 2)
		return (0);
	file = open(argv[1], O_RDONLY);
	while (file)
	{
		printf("%s", str = get_next_line(file));
		free(str);
	}
	close(file);
	return (0);
}
