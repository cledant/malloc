/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_zone_large.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 09:45:43 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 10:40:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_display_zone_large(const size_t addr, size_t *mem,
			const size_t size)
{
	sam_display_zone_header(SAM_LARGE, addr);
	sam_display_zone_alloc(addr, size);
	*mem += size;
}
