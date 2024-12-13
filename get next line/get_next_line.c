/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:47:42 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/13 09:06:29 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void freed(char *point)
{
	if (*point)
		free(point);
	point = NULL;
}

static void	*finishing(char *buffer, char **line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i])
		i++;
	j = 0;
	*line = malloc(i + 2);
	if (!*line)
		return (NULL);
	while (i >= j)
	{
		(*line)[j] = buffer[j];
		j++;
	}
	(*line)[++i] = '\n';
	(*line)[++i] = '\0';
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tohold;
	ssize_t		byts;

	line = NULL;
	if (fd > 2147483647 || (read(fd, 0, 0)) < 0)
		return (NULL);
	tohold = malloc(BUFFER_SIZE + 1);
	if (tohold)
		return (freed());
	while (!ft_strchr(tohold, '\n'))
	{
		byts = read(fd, tohold, BUFFER_SIZE);
		if (byts < 0)
			return (NULL);
		buffer = ft_strjoin(buffer, tohold);
	}
	finishing(buffer, &line);
	tohold = ft_strchr(tohold, '\n') + 1;
	return (line);
}
