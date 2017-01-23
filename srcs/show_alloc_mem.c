/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 17:09:29 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 11:03:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	show_alloc_mem(void)
{
	if (sam_reset_list() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	ft_putendl("toto1");
	if (sam_get_tiny_list() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	ft_putendl("toto2");
	if (sam_get_small_list() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	ft_putendl("toto3");
	if (sam_get_large_list() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	ft_putendl("toto4");
	if (sam_display_list() == SAM_NOP)
		return (ft_putendl("Can't display memory"));
	ft_putendl("toto5");
	sam_clean_memory();
	ft_putendl("toto6");
}
