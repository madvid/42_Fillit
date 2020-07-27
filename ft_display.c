/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 21:30:55 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/16 18:18:59 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft/libft.h"

void	ft_display(t_mappy map)
{
	int		j;
	int		i;

	j = 0;
	while (j < map.size_map)
	{
		i = 0;
		while (i < map.size_map)
			ft_putchar(map.map[j][i++]);
		ft_putchar('\n');
		j++;
	}
}

void	ft_display_unicorn(t_mappy map)
{
	int			j;
	int			i;
	char		c;
	static char	*rbw[27] = {POINT, A, B, C, D, E, F, G, H, I, J, K, L, M,
		N, O, P, Q, R, S, T, U, V, W, X, Y, Z};

	j = 0;
	while (j < map.size_map)
	{
		i = -1;
		while (++i < map.size_map)
		{
			c = 'A';
			while (map.map[j][i] != c && map.map[j][i] != '.')
				c++;
			map.map[j][i] == '.' ? ft_putstr(rbw[0]) : ft_putstr(rbw[c - 64]);
		}
		ft_putchar('\n');
		j++;
	}
}
