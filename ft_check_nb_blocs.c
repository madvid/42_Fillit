/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_nb_blocs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:25:03 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/16 18:20:45 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** FONCTION : FT_NB_BLOCS
** PARAMETRES : char *buffer |chaine de char contenant le possible tetramino|.
** DESCRIPTION :
**	 La fct vérifie que le possible tetramino contient de 4 blocs seulement.
** RETOUR :
**	 error = 0/1 si le tetramino est valide/invalide.
*/

int		ft_check_nb_blocs(char *buffer)
{
	int		error;
	int		i;
	int		nb_blocs;

	i = 0;
	nb_blocs = 0;
	while (i < 19)
	{
		if (buffer[i] == '#')
			nb_blocs++;
		i++;
	}
	error = (nb_blocs == 4) ? 0 : 1;
	return (error);
}
