/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sam_alloc_mem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:52:58 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 14:24:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main(void)
{
	size_t	i = 0;
	char	*ptr;
	char	*free_ptr;

	show_alloc_mem();
	write(1, "====================\n", 21);
	while (i < 2048)
	{
		ptr = (char *)malloc(16);
		if (i == 1500)
			free_ptr = ptr;
		i++;
	}
	i = 0;
	while (i < 8192)
	{
		ptr = (char *)malloc(128);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		ptr = (char *)malloc(9000);
		i++;
	}
	i = 0;
	show_alloc_mem();
	write(1, "====================\n", 21);
	free(free_ptr);
	show_alloc_mem();
}
