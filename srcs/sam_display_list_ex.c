/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_list_ex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:20:44 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 22:21:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		sam_display_list_ex(void)
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
		sam_display_zone_ex(info.ptr, info.type, &mem, info.size);
		i++;
	}
	sam_display_total_mem(mem);
	return (SAM_OK);
}
