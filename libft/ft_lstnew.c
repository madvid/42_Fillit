/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 12:20:53 by mdavid            #+#    #+#             */
/*   Updated: 2019/04/29 11:34:46 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*nwlist;

	if (!(nwlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		nwlist->content = NULL;
		nwlist->content_size = 0;
	}
	else
	{
		if (!(nwlist->content = (void*)malloc(sizeof(content))))
		{
			free(nwlist);
			return (NULL);
		}
		ft_memcpy(nwlist->content, content, content_size);
		nwlist->content_size = content_size;
	}
	nwlist->next = NULL;
	return (nwlist);
}
