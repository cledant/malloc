/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_zone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:02:12 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 21:07:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_display_zone(const size_t ptr, const char type, size_t *mem)
{
	if (type == SAM_TINY)
		sam_display_tiny(ptr, mem);
	else if (type == SAM_SMALL)
		sam_display_small(ptr, mem);
	else if (type == SAM_LARGE)
		sam_display_large(ptr, mem);
}
