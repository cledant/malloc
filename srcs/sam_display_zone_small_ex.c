/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_zone_small_ex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:35:58 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 22:36:43 by cledant          ###   ########.fr       */
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
							const t_small *header, size_t *mem)
{
	while (var.i < SMALL_TAB)
	{
		if (header->state[var.i] != NOT_USED)
		{
			if (var.addr == 0)
				var.addr = (size_t)header->mem + var.i * SMALL_MIN_ALLOC;
			(var.n_alloc)++;
		}
		else
		{
			if (var.n_alloc != 0 && var.addr != 0)
			{
				*mem += var.n_alloc * TINY_MIN_ALLOC;
				sam_disp_zone_alloc_ex(var.addr, var.n_alloc * SMALL_MIN_ALLOC);
			}
			var.addr = 0;
			var.n_alloc = 0;
		}
		(var.i)++;
	}
	if (header->state[var.i - 1] != NOT_USED && var.n_alloc != 0)
	{
		*mem += var.n_alloc * SMALL_MIN_ALLOC;
		sam_disp_zone_alloc_ex(var.addr, var.n_alloc * SMALL_MIN_ALLOC);
	}
}

void					sam_display_zone_small_ex(const size_t ptr, size_t *mem)
{
	t_small						*header;
	t_display_zone_tiny_small	var;

	header = (t_small *)ptr;
	if (header->used_alloc == 0)
		return ;
	init_function(&var);
	sam_display_zone_header(SAM_SMALL, (size_t)header->mem);
	display_info(var, header, mem);
}
