/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sam_alloc_mem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:52:58 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 18:38:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		main(void)
{
	size_t	i = 0;
	char	**ptr;

	show_alloc_mem();
	write(1, "====================\n", 21);
	ptr = (char **)malloc(sizeof(char *) * 60000);
	while (i < 2048)
	{
		ptr[i] = (char *)malloc(32);
		(*ptr)[i] = 42;
		i++;
	}
	show_alloc_mem();
	write(1, "====================\n", 21);
	i = 800;
	while (i < 900)
	{
		free(ptr[i]);
		i++;
	}
	i = 950;
	while (i < 1000)
	{
		free(ptr[i]);
		i++;
	}
	i = 1100;
	while (i < 1200)
	{
		free(ptr[i]);
		i++;
	}
	i = 1250;
	while (i < 1300)
	{
		free(ptr[i]);
		i++;
	}
	show_alloc_mem();
	write(1, "====================\n", 21);
	i = 0;
	while (i < 2048)
	{
		ptr[i] = (char *)malloc(32);
		(*ptr)[i] = 42;
		i++;
	}
	show_alloc_mem();
}
