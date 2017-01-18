/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_available_large.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:39:19 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 19:50:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_large			*malloc_get_available_large(void)
{
	t_large		*header;

//	write(1, "ddd1-", 5);
	if ((header = malloc_get_large()) == NULL)
		return (NULL);
//	write(1, "ddd2-", 5);
	while (header != NULL)
	{
		if (header->used_alloc + 1 <= header->max_alloc
				|| header->next == NULL)
			break ;
		header = header->next;
	}
//	write(1, "ddd3-", 5);
	if (header->used_alloc + 1 > header->max_alloc && header->next == NULL)
	{
		if (malloc_add_new_large(header) != 0)
			return (NULL);
		header = header->next;
	}
//	write(1, "ddd4-", 5);
	return (header);
}
