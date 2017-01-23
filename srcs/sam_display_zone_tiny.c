/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_zone_tiny.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 09:46:44 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 10:38:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_display_zone_tiny(const size_t ptr, size_t *mem)
{
	t_tiny	*header;
	size_t	i;
	size_t	begin_addr;
	size_t	nb_alloc;

	header = (t_tiny *)ptr;
	begin_addr = 0;
	nb_alloc = 0;
	i = 0;
	while (i < TINY_TAB)
	{
		if (header->state[i] != NOT_USED)
		{
			if (begin_addr != 0)
				begin_addr = (size_t)header->mem + i * TINY_MIN_ALLOC;
			nb_alloc++;	
		}
		else
		{
			if (nb_alloc != 0)
			{
				*mem += nb_alloc * TINY_MIN_ALLOC;
				sam_display_zone_alloc(begin_addr, nb_alloc * TINY_MIN_ALLOC);
			}
			begin_addr = 0;
			nb_alloc = 0;
		}
		i++;
	}
	if (header->state[i - 1] != NOT_USED && nb_alloc != 0)
	{
		*mem += nb_alloc * TINY_MIN_ALLOC;
		sam_display_zone_alloc(begin_addr, nb_alloc * TINY_MIN_ALLOC);
	}
}
