/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_available_tiny.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:47:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 15:16:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_tiny		*malloc_get_available_tiny(const size_t nb_alloc,
				short int *alloc_id)
{
	t_tiny	*header;

	if ((header = malloc_get_tiny()) == NULL)
		return (NULL);
	while (header != NULL)
	{
		if ((header->used_alloc + nb_alloc <= (size_t)header->max_alloc
				&& (*alloc_id = malloc_get_allocid(header->state,
				nb_alloc, TINY)) != INVALID_ALLOC) || header->next == NULL)
			break ;
		header = header->next;
	}
	if (*alloc_id == INVALID_ALLOC && header != NULL)
	{
		if (malloc_add_new_tiny(header) != 0)
			return (NULL);
		header = header->next;
		if ((*alloc_id = malloc_get_allocid(header->state, nb_alloc, TINY))
				== INVALID_ALLOC)
			return (NULL);
	}
	return (header);
}
