/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_disp_zone_alloc_ex.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:38:49 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 23:19:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_disp_zone_alloc_ex(const size_t addr, const size_t size)
{
	ft_putstr("Ox");
	sam_itoa_base_stack(addr, "0123456789ABCDEF");
	ft_putstr(" - ");
	ft_putstr("Ox");
	sam_itoa_base_stack(addr + size - 1, "0123456789ABCDEF");
	ft_putstr(" : ");
	sam_itoa_base_stack(size, "0123456789");
	ft_putendl(" octets");
	ft_putchar('\n');
	sam_hex_dump((void *)addr, size);
	ft_putchar('\n');
}
