/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarault <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:35:26 by fgarault          #+#    #+#             */
/*   Updated: 2019/04/27 18:32:28 by fgarault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			*ft_sort_integer(int *tab, int size)
{
	int		i;
	int		tmp;

	i = 0;
	while ((size - 1) > i)
	{
		if (tab[i] > tab[i + 1])
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}
