/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sam_alloc_mem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:52:58 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 16:31:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main(void)
{
	size_t	i = 0;
	char	**ptr;
	size_t	large = 0;

	show_alloc_mem();
	write(1, "====================\n", 21);
	ptr = (char **)malloc(60000);
	while (i < 2048)
	{
		ptr[i] = (char *)malloc(16);
		(*ptr)[i] = 42;
		i++;
	}
	while (i < 8192)
	{
		ptr[i] = (char *)malloc(128);
		i++;
	}
	i = 0;
	large = i;
	while (i < 16)
	{
		ptr[i] = (char *)malloc(9000);
		i++;
	}
	show_alloc_mem();
	write(1, "====================\n", 21);
/*	i = 100;
	while (i < 1500)
	{
		free(ptr[i]);
		i++;
	}
	write(1, "toto1\n", 6);
	i = 3300;
	while (i < 7800)
	{
		free(ptr[i]);
		i++;
	}
	i = large + 2;
	write(1, "toto2\n", 6);
	while (i < large + 10)
	{
		free(ptr[i]);
		i++;
	}
	write(1, "toto3\n", 6);
	show_alloc_mem();
	write(1, "====================\n", 21);*/
}
