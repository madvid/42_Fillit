/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 19:11:15 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/16 19:38:58 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fillit.h"
#include "libft/libft.h"

void	ft_error(int option)
{
	if (option == 1)
	{
		ft_putendl("usage : ./fillit [input file]");
		exit(1);
	}
	if (option == 2)
	{
		ft_putendl("error");
		exit(1);
	}
}

int		main(int ac, char **av)
{
	int		fd;
	int		nb_tetri;
	t_tetri	*lst_tetri;
	t_mappy	map;
	int		bool_c;

	fd = open(av[1], O_RDONLY);
	bool_c = 1;
	if (ac != 2)
		ft_error(1);
	if ((nb_tetri = ft_check(&fd)) == -1 || fd == -1)
		ft_error(2);
	if ((lst_tetri = ft_parsing(av[1])) == NULL)
		ft_error(2);
	map.size_map = map_min(nb_tetri);
	if (!(map.map = mapper(26)))
		ft_error(2);
	while (!(bck_trck(lst_tetri, map)))
		(map.size_map)++;
	bool_c == 1 ? ft_display(map) : ft_display_unicorn(map);
	ft_free_grid(&map);
	ft_free_chain(lst_tetri);
	return (0);
}
