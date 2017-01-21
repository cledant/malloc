/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:13:38 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 11:43:18 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free(void *ptr)
{
	size_t	addr;

	write(1, "FREE\n", 5);
	ft_putendl("ADDR TO FREE : ");
	sam_print_base((size_t)ptr, "0123456789");
	ft_putendl("");
	if (ptr == NULL)
		return ;
//	ft_putendl("IN-FREE-1");
	addr = (size_t)ptr;
//	ft_putendl("IN-FREE-2");
	if (free_tiny(addr) == FREE_OK)
		return ;
	else if (free_small(addr) == FREE_OK)
		return ;
	else if (free_large(addr) == FREE_OK)
		return ;
//	ft_putendl("IN-FREE-3");
}
