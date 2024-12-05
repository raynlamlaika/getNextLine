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


int check(char *p,int i)
{
	
}
char *get_next_line(int fd)
{
	static char	*p;
	
	if (fd < 0 || BFZ <= 0 || BFZ > 2147483647)
		return (NULL);
	p = (char *) malloc(sizeof(BFZ) + 1);
	if(!p)
		return(NULL);
	while(TRUE)
	{
		if(check(p,1))
		{
			
		}
		if ()
		{

		}
	}
	return (NULL);
}

int main()
{
	
	int i  = open ("example.txt",O_RDONLY);
	char p[10];

	read(i,p,3);
	printf("%s",p);

}