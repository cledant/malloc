/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sam_alloc_mem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:52:58 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 22:51:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main(void)
{
	size_t	i = 0;
	char	*ptr;
	char	*free_ptr;

	show_alloc_mem_ex();
	write(1, "====================\n", 21);
	while (i < 10)
	{
		ptr = (char *)malloc(16);
		ft_strcpy(ptr, "coucou ! :3");
		i++;
	}
	i = 0;
	while (i < 10)
	{
		ptr = (char *)malloc(128);
		ft_strcpy(ptr, "TVVMB ???? :x");
		i++;
	}
	show_alloc_mem_ex();
}
