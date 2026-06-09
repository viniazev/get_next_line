/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vinida-s <vinida-s@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 21:09:01 by vinida-s          #+#    #+#             */
/*   Updated: 2026/06/09 23:22:38 by vinida-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_store(int fd, char *stash)
{
	int		readstatus;
	char	*buff;

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
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

static char	*extract_line(char *stash)
{
	char	*line;
	int		i;
	int		j;

	if (stash == NULL || !stash[0])
		return (NULL);
	j = 0;
	while (stash[j] && stash[j] != '\n')
		j++;
	if (stash[j] == '\n')
		j++;
	line = malloc(sizeof(char) * (j + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (i < j)
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_separate(char *stash)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tempstash = read_store(fd, stash);
	if (!tempstash)
	{
		if (stash)
			free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = tempstash;
	line = extract_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = ft_separate(stash);
	if (!stash)
		stash = NULL;
	return (line);
}

// void	read_file(char *av)
// {
// 	int		op;
// 	char	*buffer;
// 	int		i;

// 	i = 0;
// 	op = open(av, O_RDONLY);
// 	if (op == -1)
// 	{
// 		write(2, "Cannot read file.\n", 18);
// 		return ;
// 	}
// 	buffer = get_next_line(op);
// 	while (buffer)
// 	{
// 		printf("[%d] %s", i, buffer);
// 		free(buffer);
// 		buffer = get_next_line(op);
// 		i++;
// 	}
// 	close(op);
// }

// int	main(int ac, char **av)
// {
// 	if (ac == 1)
// 		write(2, "File name missing.\n", 19);
// 	else if (ac > 2)
// 		write(2, "Too many arguments.\n", 20);
// 	else
// 		read_file(av[1]);
// 	return (0);
// }
