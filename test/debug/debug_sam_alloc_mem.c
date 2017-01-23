/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sam_alloc_mem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:52:58 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 11:52:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main(void)
{
	size_t	i = 0;
	char	*ptr;

	show_alloc_mem();
	write(1, "====================\n", 21);
	while (i < 256)
	{
		ptr = (char *)malloc(16);
		i++;
	}
	i = 0;
	while (i < 512)
	{
		ptr = (char *)malloc(128);
		i++;
	}
	i = 0;
	while (i < 16)
	{
		ptr = (char *)malloc(8192);
		i++;
	}
	i = 0;
	show_alloc_mem();
}
