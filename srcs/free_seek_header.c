/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_seek_header.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:00:29 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 12:22:02 by cledant          ###   ########.fr       */
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
