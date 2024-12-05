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
#include <fcntl.h>
#include <libc.h>

char *get_next_line(int fd)
{
	static char	*string;

	string =  malloc(sizeof(BFZ));
	while (1)
	{
		if (ft_strchr(*string,'\n'))
		{
			return(finish(string));
		}
		if ()
		{
			
		}

		
	}



}
