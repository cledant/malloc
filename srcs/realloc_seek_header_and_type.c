/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_seek_header_and_type.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:37:27 by cledant           #+#    #+#             */
/*   Updated: 2017/01/20 16:04:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		realloc_seek_header_and_type(void **header, t_type *type,
			const void *ptr)
{
	if ((*header = free_seek_header_for_addr_tiny((size_t)ptr)) != NULL)
	{
		*type = TINY;
		return (REALLOC_VALID_PTR);
	}
	else if ((*header = free_seek_header_for_addr_small((size_t)ptr)) != NULL)
	{
		*type = SMALL;
		return (REALLOC_VALID_PTR);
	}
	else if ((*header = (void *)realloc_seek_header_for_addr_large((size_t)ptr))
				!= NULL)
	{
		*type = LARGE;
		return (REALLOC_VALID_PTR);
	}
	return (REALLOC_INVALID_PTR);
}
