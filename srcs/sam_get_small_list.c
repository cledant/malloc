/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_get_small_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:56:29 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 19:30:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		sam_get_small_list(void)
{
	t_alloc_list	*list;
	t_small			*small;

	if ((small = malloc_get_small()) == NULL)
		return (SAM_OTHER);
	if ((list = sam_get_last_list()) == NULL)
		return (SAM_NOP);
	while (small != NULL)
	{
		if (list->used == ALLOC_TAB)
		{
			if (sam_add_new_list(list) == SAM_NOP)
				return (SAM_NOP);
			list = list->next;
		}
		(list->size)[list->used] = 128 * PAGESIZE;
		(list->ptr)[list->used] = (size_t)small;
		(list->type)[list->used] = SAM_SMALL;
		(list->used)++;
		small = small->next;
	}
	return (SAM_OK);
}
