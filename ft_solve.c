/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 13:33:55 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/16 18:19:28 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"
#include "libft/libft.h"

int		can_put(t_tetri *piece, t_mappy map, int i, int j)
{
	int		p;

	p = 0;
	while (p < 4)
	{
		if (j + piece->point[p].y < 0 || j + piece->point[p].y >= map.size_map)
			return (0);
		if (i + piece->point[p].x < 0 || i + piece->point[p].x >= map.size_map)
			return (0);
		if (map.map[j + piece->point[p].y][i + piece->point[p].x] != '.')
			return (0);
		p++;
	}
	return (1);
}

void	ft_put(t_tetri *piece, t_mappy map, int i, int j)
{
	int		p;

	p = 0;
	while (p < 4)
	{
		map.map[j + piece->point[p].y][i + piece->point[p].x] = piece->c;
		p++;
	}
}

void	ft_rm_block(t_tetri *piece, t_mappy map, int i, int j)
{
	int		p;

	p = 0;
	while (p < 4)
	{
		map.map[j + piece->point[p].y][i + piece->point[p].x] = '.';
		p++;
	}
}

int		bck_trck(t_tetri *lst_tetri, t_mappy map)
{
	int		i;
	int		j;

	j = 0;
	while (j < map.size_map)
	{
		i = 0;
		while (i < map.size_map)
		{
			if (can_put(lst_tetri, map, i, j))
			{
				ft_put(lst_tetri, map, i, j);
				if (lst_tetri->next == NULL || bck_trck(lst_tetri->next, map))
					return (1);
				ft_rm_block(lst_tetri, map, i, j);
			}
			i++;
		}
		j++;
	}
	return (0);
}
