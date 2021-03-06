/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:10:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/20 10:10:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc(size_t size)
{
	static char	init = 0;
	size_t		max;

	max = 0;
	max--;
	if (init == 0)
	{
		if (malloc_init(&init) != 0)
			return (NULL);
	}
	if (size <= TINY_MAX_ALLOC)
		return (malloc_tiny(size));
	else if (size > TINY_MAX_ALLOC && size <= SMALL_MAX_ALLOC)
		return (malloc_small(size));
	else if (size > SMALL_MAX_ALLOC && size <= (max - PAGESIZE - 1))
		return (malloc_large(size));
	return (NULL);
}
