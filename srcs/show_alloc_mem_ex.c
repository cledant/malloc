/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_ex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 22:19:21 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 22:20:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	show_alloc_mem_ex(void)
{
	if (sam_reset_list() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	if (sam_get_tiny_list() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	if (sam_get_small_list() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	if (sam_get_large_list() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	if (sam_display_list_ex() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	sam_clean_memory();
}
