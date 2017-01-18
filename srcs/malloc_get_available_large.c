/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_available_large.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:39:19 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 11:51:38 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_large			*malloc_get_available_large(void)
{
	t_large		*header;

	if ((header = malloc_get_large()) == NULL)
		return (NULL);
	while (header != NULL)
	{
		if (header->used_alloc + 1 <= header->max_alloc
				|| header->next == NULL)
			break ;
		header = header->next;
	}
	if (header->used_alloc + 1 > header->max_alloc && header->next == NULL)
	{
		if (malloc_add_new_large(header) != 0)
			return (NULL);
		header = header->next;
	}
	return (header);
}
