/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    get_next_line_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlamlaik <rlamlaik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:51:37 by rlamlaik          #+#    #+#             */
/*   Updated: 2024/12/03 22:51:51 by rlamlaik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptr;
	char	x;

	ptr = (char *)str;
	x = (char)c;
	i = 0;
	while (ptr[i])
	{
		if (ptr[i] == x)
			return ((char *)(ptr + i));
		i++;
	}
	if (x == '\0')
		return ((char *)(ptr + i));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*ptr;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1)+ ft_strlen(s2);
	ptr = (char *) malloc((i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (*s2)
	{
		ptr[i] = *s2;
		i++;
		s2++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char*source)
{
	size_t	o;
	char	*sp;

	o = 0;
	sp = (char *) malloc((ft_strlen(source)+ 1) * sizeof(char));
	if (!sp)
		return (NULL);
	while (source[o])
	{
		sp[o] = source[o];
		o++;
	}
	sp[o] = '\0';
	return (sp);
}


