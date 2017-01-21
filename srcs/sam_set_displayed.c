/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_get_zone_to_display.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 20:34:57 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 21:01:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		sam_get_zone_to_display(const size_t ptr)
{
	size_t			i;
	t_alloc_list	*list;

	if ((list == sam_get_list()) == NULL)
		return (0);
	i = 0;
	while (list != NULL)
	{
		while (i < ALLOC_TAB)
		{
			if ((list->ptr)[i] == smallest)
			{
				(list->disp)[i] = SAM_DISP;
				return (smallest);
			}
			i++;
		}
		i = 0;
		list = list->next;
	}
	return (0);
}
