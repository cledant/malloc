/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_seek_header_for_addr_large.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:29:25 by cledant           #+#    #+#             */
/*   Updated: 2017/01/20 12:29:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_large		*realloc_seek_header_for_addr_large(const size_t addr)
{
	size_t	i;
	t_large	*header;
	
	if ((header = malloc_get_large()) == NULL)
		return (NULL)
	i = 0;
	while (header != NULL)
	{
		while (i < LARGE_TAB)
		{
			if (addr == (header->mem)[i])
				return (header);
			i++;
		}
		i = 0;
		header = header->next;
	}
	return (NULL);
}
