/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_available_tiny.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:47:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 17:02:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_tiny		*malloc_get_available_tiny(void)
{
	t_tiny	*header;

	if ((header = malloc_get_tiny()) == NULL)
		return (NULL);
	while (header->used_alloc >= header->max_alloc && header->next != NULL)
		header = header->next;
	if (header->used_alloc >= header->max_alloc)
	{
		if (malloc_add_new_tiny(tiny) != 0)
			return (NULL);
		header = header->next;
	}
	return (header);
}
