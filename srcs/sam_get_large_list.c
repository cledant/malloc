/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_get_small_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:56:29 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 19:38:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		sam_get_large_list(void)
{
	t_alloc_list	*list;
	t_large			*large;
	size_t			i;

	if ((large = malloc_get_large()) == NULL)
		return (SAM_OTHER);
	if ((list = sam_get_last_list()) == NULL)
		return (SAM_NOP);
	i = 0;
	while (large != NULL)
	{
		while (i < LARGE_TAB)
		{
			if (list->used == ALLOC_TAB)
			{
				if (sam_add_new_list(list) == SAM_NOP)
					return (SAM_NOP);
				list = list->next;
			}
			if ((large->size)[i] != 0)
			{
				(list->size)[list->used] = (large->size)[i];
				(list->ptr)[list->used] = (large->mem)[i];
				(list->type)[list->used] = SAM_LARGE;
				(list->used)++;
			}
			i++;
		}
		i = 0;
		large = large->next;
	}
	return (SAM_OK);
}
