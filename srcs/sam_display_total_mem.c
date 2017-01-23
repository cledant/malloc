/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_display_total_mem.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 09:43:01 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 10:43:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_display_total_mem(const size_t size)
{
	ft_putstr("Total : ");
	sam_itoa_base_stack(size, "0123456789");
	ft_putendl(" octets");
}
