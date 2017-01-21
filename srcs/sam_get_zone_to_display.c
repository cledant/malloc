/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_get_zone_to_display.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 20:34:57 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 20:57:06 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		sam_get_zone_to_display(char *type)
{
	size_t			smallest;
	size_t			i;
	t_alloc_list	*list;

	if ((list == sam_get_list()) == NULL)
		return (0);
	smallest = 0;
	smallest--;
	i = 0;
	while (list != NULL)
	{
		while (i < ALLOC_TAB)
		{
			if ((list->ptr)[i] < smallest && (list->disp)[i] == SAM_NOT_DISP)
			{
				smallest = (list->ptr)[i];
				*type = (list->ptr)[i];
			}
			i++;
		}
		i = 0;
		list = list->next;
	}	
	return (sam_set_displayed(smallest));
}
