/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_clean_prealloc_large.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:54:13 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 13:59:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		malloc_clean_prealloc_large(t_large **header)
{
	size_t		i;
	void		*ptr;

	i = 0;
	ptr = NULL;
	while (i < LARGE_PREALLOC)
	{
		ptr = (*header)->(mem + i * sizeof(void *));
		if (ptr != NULL)
			munmap(ptr, 2 * PAGESIZE);
		i++;
	}
	munmap(*header, PAGESIZE);
	*header = NULL;
	return (-1);
}
