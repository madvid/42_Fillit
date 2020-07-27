/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 03:54:07 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/16 18:19:37 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/libft.h"
#include "fillit.h"

void	ft_free_grid(t_mappy *grid)
{
	int		i;

	i = 0;
	if (grid)
	{
		while (grid->map[i])
		{
			free(grid->map[i]);
			i++;
		}
		free((void*)grid->map);
		grid = NULL;
	}
}

void	ft_free_chain(t_tetri *lst)
{
	t_tetri *tmp;

	tmp = lst;
	while (tmp != NULL)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

int		map_min(int size)
{
	int		i;

	i = 1;
	size *= 4;
	while (i * i < size)
		i++;
	return (i);
}

char	**mapper(int size)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	if (!(map = (char**)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	map[size] = 0;
	while (j < size)
	{
		if (!(map[j] = (char*)malloc(sizeof(char) * (size + 1))))
			return (NULL);
		map[j][size] = '\0';
		i = 0;
		while (i <= size)
		{
			map[j][i] = '.';
			i++;
		}
		j++;
	}
	return (map);
}
