/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:47:42 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/13 14:18:18 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void freed(char **point)
{
	if (*point)
	{
		free(*point);
		*point = NULL;
	}
}

static void	*finishing(char *buffer, char **line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' || !buffer[i])
		i++;
	j = 0;
	*line = malloc(i + 2);
	if (!*line)
		return (NULL);
	while (i > j && buffer[j] != '\n')
	{
		(*line)[j] = buffer[j];
		j++;
	}
	if (buffer[i] == '\n')
        (*line)[j++] = '\n';
	(*line)[j] = '\0';
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;
	char		*tohold;
	ssize_t		byts;

	line = NULL;
	if (BUFFER_SIZE > 2147483647 || (read(fd, 0, 0)) < 0 || fd < 0)
		return (NULL);
	tohold = malloc((size_t)BUFFER_SIZE + 1);
	if (!tohold)
		return (NULL);
	while (!buffer || !ft_strchr(tohold, '\n'))
	{
		byts = read(fd, tohold, BUFFER_SIZE);
		if (byts <= 0)
		{
            freed(&tohold);
            return (freed(&buffer), NULL);
        }
		tohold[byts] = '\0';
		buffer = ft_strjoin(buffer, tohold);
		if (!buffer)
			return (freed(&tohold), NULL);
	}
	freed(&tohold);
    if (!finishing(buffer, &line))
        return (freed(&buffer), NULL);

    char *temp = buffer;
	buffer = ft_strdup(ft_strchr(buffer, '\n') + 1);
	
    return (line);
}

int main()
{
	int i = open("example.txt",O_RDONLY); 
	printf("%s",get_next_line(i));


	return (0);
}