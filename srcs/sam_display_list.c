/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:44:33 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 11:25:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		sam_display_list(void)
{
	size_t			max_print;
	size_t			i;
	size_t			mem;
	t_display_info	info;

	i = 0;
	mem = 0;
	max_print = sam_get_max_print();
	while (i < max_print)
	{
		if ((info.ptr = sam_get_zone_to_display(&(info.type),
				&(info.size))) == 0)
			return (SAM_NOP);
		sam_display_zone(info.ptr, info.type, &mem, info.size);
		i++;
	}
	sam_display_total_mem(mem);
	return (SAM_OK);
}
