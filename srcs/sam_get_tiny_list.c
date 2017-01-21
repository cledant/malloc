/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_get_tiny_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:42:37 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 19:28:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		sam_get_tiny_list(void)
{
	t_alloc_list	*list;
	t_tiny			*tiny;

	if ((tiny = malloc_get_tiny()) == NULL)
		return (SAM_OTHER);
	if ((list = sam_get_last_list()) == NULL)
		return (SAM_NOP);
	while (tiny != NULL)
	{
		if (list->used == ALLOC_TAB)
		{
			if (sam_add_new_list(list) == SAM_NOP)
				return (SAM_NOP);
			list = list->next;
		}
		(list->size)[list->used] = 4 * PAGESIZE;
		(list->ptr)[list->used] = (size_t)tiny;
		(list->type)[list->used] = SAM_TINY;
		(list->used)++;
		tiny = tiny->next;
	}
	return (SAM_OK);
}
