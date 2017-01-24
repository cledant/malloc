/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:10:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 15:39:53 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc(size_t size)
{
	static char	init = 0;
	size_t		max;

	ft_putendl("malloc");
	max = 0;
	max--;
	if (init == 0)
	{
		if (malloc_init(&init) != 0)
			return (NULL);
	}
	if (size <= TINY_MAX_ALLOC)
	{
		ft_putendl("tiny");
		return (malloc_tiny(size));
	}
	else if (size > TINY_MAX_ALLOC && size <= SMALL_MAX_ALLOC)
	{
		ft_putendl("small");
		return (malloc_small(size));
	}
	else if (size > SMALL_MAX_ALLOC && size <= (max - PAGESIZE - 1))
	{
		ft_putendl("large");
		return (malloc_large(size));
	}
	return (NULL);
}
