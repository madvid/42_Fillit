/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 12:03:39 by mdavid            #+#    #+#             */
/*   Updated: 2019/06/16 18:20:12 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "fillit.h"

/*
** FONCTION : CHECK
** PARAMETRE(S) : int fd  |le fd du fichier contenant les tetraminos|
** DESCRIPTION :
**		La fct vérifie l'intégralité du fichier supposé contenir les tetraminos
** RETOUR :
** error = -1/0/1 -> -1 = il y a eu un pb d'allocation ou lecture,
**			0 = le fichier contenant les tetraminos est valide
**			1 = le fichier contenant les tetraminos est invalide.
*/

int		ft_check(int *fd)
{
	char	*buf;
	char	buf1[1];
	int		ret;
	int		nb_tetramino;

	ret = 3;
	nb_tetramino = 0;
	if (read(*fd, buf1, 0) == -1 || !(buf = (char*)malloc(sizeof(char) * 21)))
		return (-1);
	buf[20] = '\0';
	while (ret != 0 && nb_tetramino <= 26)
	{
		if ((ret = read(*fd, buf, 20)) != 20 || ft_check_form(buf) == 1
				|| ft_check_tetramino(&buf) == 1)
		{
			free(buf);
			return (-1);
		}
		if ((ret = read(*fd, buf1, 1)) == 1)
			if (buf1[0] != '\n')
				return (-1);
		nb_tetramino++;
	}
	free(buf);
	return (nb_tetramino == 0 || nb_tetramino > 26 ? -1 : nb_tetramino);
}
