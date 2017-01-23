/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_zone_header.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 09:28:56 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 09:33:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_display_zone_header(const char type, const size_t addr)
{
	if (type == SAM_TINY)
		ft_putstr("TINY : ");
	else if (type == SAM_SMALL)
		ft_putstr("SMALL : ");
	else if (type == SAM_LARGE)
		ft_putstr("LARGE : ");
	sam_itoa_base_stack(addr, "0123456789ABCDEF");
}
