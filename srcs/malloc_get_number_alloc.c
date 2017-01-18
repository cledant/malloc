/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_number_alloc.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:45:26 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 09:11:22 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		malloc_get_number_alloc(const size_t size, const size_t size_alloc,
				const t_type type)
{
	size_t	alloc;

	alloc = size / size_alloc;
	if (size % size_alloc != 0)
		alloc++;
	if (type == TINY && alloc > TINY_TAB)
		return (0);
	else if (type == SMALL && alloc > SMALL_TAB)
		return (0);
	return (alloc);
}
