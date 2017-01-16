/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_tiny.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:05:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 19:41:21 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_tiny	*malloc_get_tiny(void)
{
	static t_tiny	*tiny = NULL;
	static char		alloc = 0;

	if (alloc == 0)
	{
		if ((tiny = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			tiny = NULL;
		if (tiny != NULL)
		{
			tiny->prev = NULL;
			tiny->next = NULL;
			tiny->size = PAGESIZE;
			tiny->used = 2 * sizeof(size_t) + 2 * sizeof(void *);
			alloc = 1;
		}
	}
	return (tiny);
}
