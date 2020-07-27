/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:12:14 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/16 18:22:13 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

void	ft_set_point(char *buffer, t_tetri *new_element)
{
	int		i;
	int		y_p;
	int		x_p;
	int		n;

	i = 0;
	y_p = 0;
	x_p = 0;
	n = 0;
	while (buffer[i])
	{
		if (buffer[i] == '#')
		{
			if (n == 0)
			{
				y_p = (i + 1) / 5;
				x_p = (i + 1) % 5;
			}
			new_element->point[n].y = ((i + 1) / 5) - y_p;
			new_element->point[n++].x = ((i + 1) % 5) - x_p;
		}
		i++;
	}
}

t_tetri	*lstadd(char *buffer, t_tetri *element, char c)
{
	t_tetri *start;
	t_tetri *new_element;

	if (!(new_element = (t_tetri*)malloc(sizeof(t_tetri))))
		return (NULL);
	start = element;
	if (element)
	{
		while (element->next != NULL)
			element = element->next;
		element->next = new_element;
	}
	new_element->c = c;
	ft_set_point(buffer, new_element);
	new_element->next = NULL;
	if (element == NULL)
		return (new_element);
	return (start);
}

t_tetri	*ft_parsing(char *av)
{
	int		fd;
	int		ret;
	t_tetri	*lst_tetri;
	char	buffer[21];
	char	c;

	fd = open(av, O_RDONLY);
	ret = 0;
	lst_tetri = NULL;
	c = 'A';
	while ((ret = read(fd, buffer, 21)))
	{
		buffer[ret] = '\0';
		if ((lst_tetri = lstadd(buffer, lst_tetri, c)) == NULL)
		{
			ft_free_chain(lst_tetri);
			return (NULL);
		}
		c++;
	}
	close(fd);
	return (lst_tetri);
}
