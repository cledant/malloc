/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:20:55 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 19:45:31 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_small		*malloc_get_small(void)
{
	static void		*small = NULL;
	static char		alloc = 0;

	if (alloc == 0)
	{
		if ((small = mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			small = NULL;
		if (small != NULL)
		{
			small->prev = NULL;
			small->next = NULL;
			small->size = PAGESIZE;
			small->used = 2 * sizeof(size_t) + 2 * sizeof(void *);
			alloc = 1;
		}
	}
	return (small);
}
