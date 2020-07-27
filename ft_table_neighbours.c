/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_neighbours.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:22:35 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/16 18:21:30 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** FONCTION : FT_BLOCS_UPDOWN
** PARAMETRES : char *buffer (le possible tetramino),
**				int i (la position du bloc).
** DESCRIPTION :
**     	Vérifie quand c'est possible s'il y a des blocs voisins juste au
** 		dessus et juste en dessous.
** RETOUR :
**     0/1/2 -> le nombre de blocs voisins.
*/

int		ft_blocs_updown(char *buffer, int i)
{
	int		nghbr_ud;

	nghbr_ud = 0;
	if (i < 14)
	{
		if (buffer[i + 5] == '#')
			nghbr_ud++;
	}
	if (i > 4)
	{
		if (buffer[i - 5] == '#')
			nghbr_ud++;
	}
	return (nghbr_ud);
}

/*
**FONCTION : FT_BLOCS_LEFTRIGHT
** PARAMETRES : char *buffer (le possible tetramino),
**				int i (la position du bloc).
** DESCRIPTION :
**     Vérifie quand c'est possible s'il y a des blocs voisins juste à
**	gauche et juste à droite.
** RETOUR :
**     0/1/2 -> le nombre de blocs voisins.
*/

int		ft_blocs_leftright(char *buffer, int i)
{
	int		nghbr_lr;

	nghbr_lr = 0;
	if ((i + 2) % 5 != 0)
	{
		if (buffer[i + 1] == '#')
			nghbr_lr++;
	}
	if (i % 5 != 0)
	{
		if (buffer[i - 1] == '#')
			nghbr_lr++;
	}
	return (nghbr_lr);
}

/*
** FONCTION : FT_TABLE_NEIGHBOURS
** PARAMETRES : int **table |tableau 2D de int, semblable à une matrice|,
**			  buffer |string, contenant le 21 char, donc une possible
**				piece de tetramino|.
** DESCRIPTION :
**   rempli le tableau de voisin:
**	   + Cherche un bloc unitaire #,
**	   + Compte le nombre de blocs unitaires autour du bloc trouvé,
**	   + Place dans le tableau la valeur du nombre de voisin.
** RETOUR :
**	 retourne la somme des voisins de tous les blocs.
*/

int		ft_table_neighbours(int **table, char *buffer)
{
	int		sum_nghbr;
	int		i;

	i = 0;
	while (buffer[i] && i < 19)
	{
		while (buffer[i] != '#' && i < 19)
			i++;
		if (buffer[i] == '#' && i < 19)
			table[i / 5][i % 5] = ft_blocs_updown(buffer, i)
				+ ft_blocs_leftright(buffer, i);
		i++;
	}
	i = 0;
	sum_nghbr = 0;
	while (i < 19)
	{
		sum_nghbr = sum_nghbr + table[i / 5][i % 5];
		i++;
	}
	return (sum_nghbr);
}
