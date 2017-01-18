/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_prealloc_large.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:28:07 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 13:52:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		malloc_prealloc_large(t_large **header)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = NULL;
	while (i < LARGE_PREALLOC)
	{
		if ((ptr = mmap(NULL, 2 * PAGESIZE, PROT_READ | PROT_WRITE,
				MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (malloc_clean_prealloc_large(header));
		(*header)->(mem + i * sizeof(void *)) = ptr;
		(*header)->(size[i]) = 2 * PAGESIZE;
		((*header)->used_alloc)++;
		i++;
	}
	return (0);
}
