/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:02:37 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 15:34:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc(void *ptr, size_t size)
{
	t_type		type;
	void		*header;
	void		*new_ptr;

	ft_putendl("realloc");
	if (ptr == NULL)
		return ((void *)malloc(size));
	new_ptr = NULL;
	if (realloc_seek_header_and_type(&header, &type, ptr)
			== REALLOC_INVALID_PTR)
		return (NULL);
	if (type == TINY)
		return (realloc_tiny((t_tiny *)header, ptr, size));
	else if (type == SMALL)
		return (realloc_small((t_small *)header, ptr, size));
	else if (type == LARGE)
		return (realloc_large((t_large *)header, ptr, size));
	return (new_ptr);
}
