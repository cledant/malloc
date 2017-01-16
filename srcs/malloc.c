/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:10:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 15:34:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc(size_t size)
{
	void		*ptr;
	static char	init = 0;

	if (init == 0)
	{
		if (malloc_init(&init) != 0)
			return (NULL);
	}
	if (size <= TINY_SIZE)
		return (malloc_tiny(size));
	else if (size > TINY_SIZE && size <= SMALL_SIZE)
		return (malloc_small(size));
	else if (size > SMALL_SIZE)
		return (malloc_large(size));
	return (NULL);
}
