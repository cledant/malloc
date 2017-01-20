/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_allocid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:22:39 by cledant           #+#    #+#             */
/*   Updated: 2017/01/20 10:57:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static int	init_allocid(t_allocid *alloc, const t_type type)
{
	if (type == LARGE)
		return (0);
	alloc->i = 0;
	alloc->id_ok = INVALID_ALLOC;
	alloc->free = 0;
	alloc->max = (type == TINY) ? TINY_TAB : SMALL_TAB;
	return (1);
}

short int	malloc_get_allocid(const short int *state, const size_t nb_alloc,
				const t_type type)
{
	t_allocid	alloc;

	if (init_allocid(&alloc, type) == 0)
		return (INVALID_ALLOC);
	while (alloc.i < alloc.max)
	{
		if (state[alloc.i] != NOT_USED)
		{
			alloc.free = 0;
			alloc.id_ok = INVALID_ALLOC;
		}
		else
		{
			if (alloc.free == 0)
				alloc.id_ok = alloc.i;
			(alloc.free)++;
		}
		if (alloc.free == nb_alloc)
			return (alloc.id_ok);
		(alloc.i)++;
	}
	return (INVALID_ALLOC);
}
