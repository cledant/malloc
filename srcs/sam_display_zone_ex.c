/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_zone_ex.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:22:15 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 22:23:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_display_zone_ex(const size_t ptr, const char type, size_t *mem,
			const size_t zone_size)
{
	if (type == SAM_TINY)
		sam_display_zone_tiny_ex(ptr, mem);
	else if (type == SAM_SMALL)
		sam_display_zone_small_ex(ptr, mem);
	else if (type == SAM_LARGE)
		sam_display_zone_large_ex(ptr, mem, zone_size);
}
