/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 21:09:01 by vinida-s          #+#    #+#             */
/*   Updated: 2026/06/09 23:19:29 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_store(int fd, char *stash)
{
	int		readstatus;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (free(stash), NULL);
	while (!ft_strchr(stash, '\n'))
	{
		readstatus = read(fd, buff, BUFFER_SIZE);
		if (readstatus == -1)
			return (free(buff), free(stash), stash = NULL, NULL);
		if (readstatus == 0)
			break ;
		buff[readstatus] = '\0';
		stash = ft_strjoin(stash, buff);
	}
	free(buff);
	return (stash);
}

static char	*extract_line(char *stash, int newline_pos)
{
	char	*line;
	int		i;

	if (stash == NULL || !stash[0])
		return (NULL);
	line = malloc(sizeof(char) * (newline_pos + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < newline_pos)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_separate(char *stash, int newline_pos)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stash)
		return (NULL);
	i = newline_pos;
	if (!stash[i] || !stash[i + 1])
		return (free(stash), stash = NULL, NULL);
	i++;
	str = malloc(sizeof(char) * (ft_strlen(stash + i) + 1));
	if (!str)
		return (free(stash), stash = NULL, NULL);
	j = 0;
	while (stash[i])
	{
		str[j] = stash[i];
		j++;
		i++;
	}
	str[j] = '\0';
	free(stash);
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*tempstash;
	char		*line;
	int			newline_pos;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(stash), stash = NULL, NULL);
	tempstash = read_store(fd, stash);
	if (!tempstash)
	{
		stash = NULL;
		return (NULL);
	}
	stash = tempstash;
	newline_pos = 0;
	while (stash[newline_pos] && stash[newline_pos] != '\n')
		newline_pos++;
	if (stash[newline_pos] == '\n')
		newline_pos++;
	line = extract_line(stash, newline_pos);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = ft_separate(stash, newline_pos - 1);
	if (!stash)
		stash = NULL;
	return (line);
}

void	read_file(char *av)
{
	int		op;
	char	*buffer;
	int		i;

	i = 0;
	op = open(av, O_RDONLY);
	if (op == -1)
	{
		write(2, "Cannot read file.\n", 18);
		return ;
	}
	buffer = get_next_line(op);
	while (buffer)
	{
		printf("[%d] %s", i, buffer);
		free(buffer);
		buffer = get_next_line(op);
		i++;
	}
	close(op);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		write(2, "File name missing.\n", 19);
	else if (ac > 2)
		write(2, "Too many arguments.\n", 20);
	else
		read_file(av[1]);
	return (0);
}
