/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_seek_and_deallocate_large.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:54:03 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 19:54:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

inline int	free_seek_and_deallocate_large(const size_t addr, t_large *header)
{
	size_t	i;

	i = 0;
	while (i < LARGE_TAB)
	{
		if (addr == (header->mem)[i])
		{
			if (header->used_alloc == 0)
				return (FREE_NOP);
			(header->used_alloc)--;
			munmap((void *)(header->mem)[i], (header->size)[i]);
			(header->size)[i] = NOT_USED;
			(header->mem)[i] = NOT_USED;
			if (header->used_alloc == 0 && header->prev != NULL)
				free_check_to_delete_header_large(header);
			return (FREE_OK);
		}
		i++;
	}
	return (FREE_NOP);
}
