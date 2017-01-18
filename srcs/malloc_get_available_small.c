/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_available_small.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 10:41:33 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 15:18:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_small		*malloc_get_available_small(const size_t nb_alloc,
				short int *alloc_id)
{
	t_small		*header;

	if ((header = malloc_get_small()) == NULL)
		return (NULL);
	while (header != NULL)
	{
		if ((header->used_alloc + nb_alloc <= (size_t)header->max_alloc
				&& (*alloc_id = malloc_get_allocid(header->state,
				nb_alloc, SMALL)) != INVALID_ALLOC) || header->next == NULL)
			break ;
		header = header->next;
	}
	if (*alloc_id == INVALID_ALLOC && header != NULL)
	{
		if (malloc_add_new_small(header) != 0)
			return (NULL);
		header = header->next;
		if ((*alloc_id = malloc_get_allocid(header->state, nb_alloc, SMALL))
				== INVALID_ALLOC)
			return (NULL);
	}
	return (header);
}
