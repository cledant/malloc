/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_get_small_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:56:29 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 21:03:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static inline void		get_info_large(t_list_alloc *list, t_large *large,
							const size_t i)
{
	(list->size)[list->used] = (large->size)[i];
	(list->ptr)[list->used] = (large->mem)[i];
	(list->type)[list->used] = SAM_LARGE;
	(list->used)++;
}

static inline int		get_info(t_large *large, t_list_alloc *list, size_t i)
{
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
				get_info_large(list, large, i);
			i++;
		}
		i = 0;
		large = large->next;
	}
	return (SAM_OK);
}

int						sam_get_large_list(void)
{
	t_list_alloc	*list;
	t_large			*large;
	size_t			i;

	if ((large = malloc_get_large()) == NULL)
		return (SAM_OTHER);
	if ((list = sam_get_last_list()) == NULL)
		return (SAM_NOP);
	i = 0;
	return (get_info(large, list, i));
}
