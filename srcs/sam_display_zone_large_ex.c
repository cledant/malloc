/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_zone_large_ex.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:37:13 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 22:43:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_display_zone_large_ex(const size_t addr, size_t *mem,
			const size_t size)
{
	sam_display_zone_header(SAM_LARGE, addr);
	sam_disp_zone_alloc_ex(addr, size);
	*mem += size;
}
