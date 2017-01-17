/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_allocid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 16:22:39 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 19:15:14 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

short int	malloc_get_allocid(const short int *state, const size_t nb_alloc,
				const t_type type)
{
	size_t		i;
	short int	id_ok;
	size_t		free;
	size_t		max;

	i = 0;
	id_ok = INVALID_ALLOC;
	free = 0;
	if (type == LARGE)
		return (INVALID_ALLOC);
	else if (type == TINY)
		max = TINY_TAB;
	else
		max = SMALL_TAB;
	while (i < max)
	{
		if (state[i] != NOT_USED)
		{
			free = 0;
			id_ok = INVALID_ALLOC;
		}
		else
		{
			if (free == 0)
				id_ok = i;
			free++;
		}
		if (free == nb_alloc)
			return (id_ok);
		i++;
	}
	return (INVALID_ALLOC);
}
