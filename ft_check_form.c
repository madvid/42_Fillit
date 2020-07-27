/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_form.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 15:50:34 by fgarault          #+#    #+#             */
/*   Updated: 2019/06/16 18:20:37 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "fillit.h"

/*
** FONCTION : CHECK_FORM
** PARAMETRE(S) : adresse d'une string.
** DESCRIPTION :
**	 Reçoit le buffer depuis la fonction CHECK()
**	 Permet de vérifier si le buffer a les caractéristiques d'un tetramino
**	 potentiel en vérifiant que l'on a 4 caracteres ('#'||'.') suivi d'un \n
**	 pour les trois 1eres lignes et d'un '\n'||'\0' pour la derniere ligne.
** RETOUR :
**		1 -> le buffer reçu n'a pas la forme d'un potentiel tetramino.
**		0 -> le buffer reçu a la forme d'un potentiel tetramino.
*/

int		ft_check_form(char *buffer)
{
	int			i;
	int			error;
	int			mod;

	i = 0;
	error = 0;
	mod = 0;
	while (buffer[i] && i < 19 && error == 0)
	{
		if ((i == 0) || ((mod = (i + 1) % 5) > 0))
		{
			if (buffer[i] == '.' || buffer[i] == '#')
				i++;
			else
				error = 1;
		}
		else if (buffer[i] == '\n' && ((mod = (i + 1) % 5) == 0))
			i++;
		else
			error = 1;
	}
	if (!(buffer[19] == '\n' || buffer[19] == '\0'))
		error = 1;
	return (error);
}
