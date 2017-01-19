/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_seek_header_for_addr_small.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:43:28 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 17:45:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_small		*free_seek_header_for_addr_small(const size_t addr)
{
	t_small		*header;
	size_t		addr_mem;

	addr_mem = 0;
	if ((header = malloc_get_small()) == NULL)
		return (NULL);
	while (header != NULL)
	{
		addr_mem = (size_t)header->mem;
		if (addr >= addr_mem && addr < (addr_mem + 128 * PAGESIZE))
			return (header);
		header = header->next;
	}
	return (header);
}
