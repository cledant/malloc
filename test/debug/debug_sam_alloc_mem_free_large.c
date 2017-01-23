/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_sam_alloc_mem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:52:58 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 18:48:25 by cledant          ###   ########.fr       */
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
	while (i < 128)
	{
		ptr[i] = (char *)malloc(4097);
		(*ptr)[i] = 42;
		i++;
	}
	show_alloc_mem();
	write(1, "====================\n", 21);
	i = 10;
	while (i < 20)
	{
		free(ptr[i]);
		i++;
	}
	i = 32;
	while (i < 64)
	{
		free(ptr[i]);
		i++;
	}
	i = 64;
	while (i < 69)
	{
		free(ptr[i]);
		i++;
	}
	i = 80;
	while (i < 90)
	{
		free(ptr[i]);
		i++;
	}
	show_alloc_mem();
	write(1, "====================\n", 21);
	i = 0;
	while (i < 30)
	{
		ptr[i] = (char *)malloc(4097);
		(*ptr)[i] = 42;
		i++;
	}
	show_alloc_mem();
}
