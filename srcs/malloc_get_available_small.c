/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_available_small.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:40:08 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 19:41:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_small		*malloc_get_available_small(void)
{
	t_small		*header;

	if ((header = malloc_get_small()) == NULL)
		return (NULL);
	while (header->used_alloc >= header->max_alloc && header->next != NULL)
		header = header->next;
	if (header->used_alloc >= header->max_alloc)
	{
		if (malloc_add_new_small(tiny) != 0)
			return (NULL);
		header = header->next;
	}
	return (header);
}
