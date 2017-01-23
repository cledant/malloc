/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_zone_alloc.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 09:34:30 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 11:41:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_display_zone_alloc(const size_t addr, const size_t size)
{
	ft_putstr("Ox");
	sam_itoa_base_stack(addr, "0123456789ABCDEF");
	ft_putstr(" - ");
	ft_putstr("Ox");
	sam_itoa_base_stack(addr + size - 1, "0123456789ABDCEF");
	ft_putstr(" : ");
	sam_itoa_base_stack(size, "0123456789");
	ft_putendl(" octets");
}
