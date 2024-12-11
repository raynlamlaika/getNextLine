/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:47:42 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/05 02:56:42 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*append(char *string, char *result)
{
	char	*p;

	if (!result)
		p = ft_strdup(string);
	else
	{
		p = ft_strjoin(result, string);
		free(result);
	}
	return (p);
}

static char *finishing(char *result)
{
	int	i;

	i = 0;
	if (!result)
		return (NULL);
	while (result[i] && result[i] != '\n')
		i++;
	if (result[i] == '\n')
		result[++i] = '\0';
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*buff;
	char		retu[BUFFER_SIZE + 1];
	ssize_t	byts;

	buff = NULL;
	while (1)
	{
		if (buff && ft_strchr(buff,'\n'))
		{
			printf("hada howa: %s \n",ft_strchr(buff,'\n'));
			break;
		}
		byts = read(fd, retu, BUFFER_SIZE);
		if (byts <= 0)
			break;
		retu[byts] = '\0';
		buff = append(retu,buff);
	}
}


int main()
{
	int i = open("example.txt",O_RDONLY);
	printf("%s",get_next_line(i));
	//printf("%s",get_next_line(i));

	// static char	*buffer;
	// char		temp[BUFFER_SIZE + 1];
	// ssize_t		bytes_read;
	// char		*line;
	// char		*newline;

	// line = NULL;
	// buffer = NULL;
	// while (1)
	// {
	// 	if (buffer && ft_strchr(buffer, '\n'))
	// 	{
	// 		newline = ft_strchr(buffer, '\n');
	// 		size_t len = newline - buffer + 1;
	// 		line = malloc(len + 1);
	// 		if (line)
	// 		{
	// 			strncpy(line, buffer, len);
	// 			line[len] = '\0';
	// 		}
	// 		memmove(buffer, buffer + len, ft_strlen(buffer) - len + 1);
	// 		return (line);
	// 	}
	// 	bytes_read = read(fd, temp, BUFFER_SIZE);
	// 	if (bytes_read <= 0)
	// 		break;
	// 	temp[bytes_read] = '\0';
	// 	buffer = append(temp, buffer);
	// }

	// if (buffer && *buffer)
	// {
	// 	line = ft_strdup(buffer);
	// 	free(buffer);
	// 	buffer = NULL;
	// 	return (line);
	// }

	// free(buffer);
	// buffer = NULL;
	// return (NULL);


	return 0;
}