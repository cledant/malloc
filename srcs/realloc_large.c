/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:35:50 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 15:17:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc_large(t_large *header, void *ptr, const size_t new_size)
{
	size_t	alloc_id;

	alloc_id = 0;
	while (alloc_id < LARGE_TAB)
	{
		if ((header->mem)[alloc_id] == (size_t)ptr)
			break ;
		alloc_id++;
	}
	if ((header->mem)[alloc_id] != (size_t)ptr)
		return (NULL);
	if ((header->size)[alloc_id] >= new_size)
		return (ptr);
	else
		return (realloc_new_ptr(ptr, new_size, (header->size)[alloc_id]));
}
