/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_zone_tiny.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 09:46:44 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 20:47:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static inline void		init_function(t_display_zone_tiny_small *ptr)
{
	ptr->i = 0;
	ptr->addr = 0;
	ptr->n_alloc = 0;
}

static inline void		display_info(t_display_zone_tiny_small var,
							const t_tiny *header, size_t *mem)
{
	while (var.i < TINY_TAB)
	{
		if (header->state[var.i] != NOT_USED)
		{
			if (var.addr == 0)
				var.addr = (size_t)header->mem + var.i * TINY_MIN_ALLOC;
			(var.n_alloc)++;
		}
		else
		{
			if (var.n_alloc != 0 && var.addr != 0)
			{
				*mem += var.n_alloc * TINY_MIN_ALLOC;
				sam_display_zone_alloc(var.addr, var.n_alloc * TINY_MIN_ALLOC);
			}
			var.addr = 0;
			var.n_alloc = 0;
		}
		(var.i)++;
	}
	if (header->state[var.i - 1] != NOT_USED && var.n_alloc != 0)
	{
		*mem += var.n_alloc * TINY_MIN_ALLOC;
		sam_display_zone_alloc(var.addr, var.n_alloc * TINY_MIN_ALLOC);
	}
}

void					sam_display_zone_tiny(const size_t ptr, size_t *mem)
{
	t_tiny						*header;
	t_display_zone_tiny_small	var;

	header = (t_tiny *)ptr;
	if (header->used_alloc == 0)
		return ;
	init_function(&var);
	sam_display_zone_header(SAM_TINY, (size_t)header->mem);
	display_info(var, header, mem);
}
