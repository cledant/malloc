/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:02:37 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 20:11:29 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*reallocf(void *ptr, size_t size)
{
	t_type		type;
	void		*header;
	void		*new_ptr;

	if (ptr == NULL)
		return ((void *)malloc(size));
	new_ptr = NULL;
	if (realloc_seek_header_and_type(&header, &type, ptr)
			== REALLOC_INVALID_PTR)
		return (NULL);
	if (type == TINY)
		return (reallocf_wrapper(ptr,
					realloc_tiny((t_tiny *)header, ptr, size)));
	else if (type == SMALL)
		return (reallocf_wrapper(ptr,
					realloc_small((t_small *)header, ptr, size)));
	else if (type == LARGE)
	{
		return (reallocf_wrapper(ptr,
					realloc_large((t_large *)header, ptr, size)));
	}
	return (new_ptr);
}
