/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_seek_header_for_addr_tiny.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:11:15 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 17:11:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_tiny	*free_seek_header_for_addr_tiny(const size_t addr)
{
	t_tiny		*header;
	size_t		addr_mem;

	addr_mem = 0;
	if ((header = malloc_get_tiny()) == NULL)
		return (NULL);
	while (header != NULL)
	{
		addr_mem = (size_t)header->mem;
		if (addr >= addr_mem && addr < (addr_mem + 4 * PAGESIZE))
			return (header);
		header = header->next;
	}
	return (header);
}
