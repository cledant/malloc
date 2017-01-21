/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 19:44:33 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 20:16:35 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		sam_display_list(void)
{
	char			type;
	size_t			max_print;
	size_t			i;
	size_t			ptr;
	size_t			mem;

	i = 0;
	mem = 0;
	max_print = sam_get_max_print();
	while (i < max_print)
	{
		if ((ptr = sam_get_zone_to_display(&type)) == 0)
			return (SAM_NOP);
		sam_display_zone(ptr, type, &mem);
		i++;
	}
	return (SAM_OK);
}
