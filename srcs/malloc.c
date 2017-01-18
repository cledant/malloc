/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:10:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 17:12:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc(size_t size)
{
	static char	init = 0;

//	write(1, "toto1-", 6);
	if (init == 0)
	{
//		write(1, "toto2-", 6);
		if (malloc_init(&init) != 0)
		{
//			write(1, "toto3-", 6);
			return (NULL);
		}
	}
	if (size <= TINY_MAX_ALLOC)
	{
//		write(1, "toto4-", 6);
		return (malloc_tiny(size));
	}
	else if (size > TINY_MAX_ALLOC && size <= SMALL_MAX_ALLOC)
	{
//		write(1, "toto5-", 6);
		return (malloc_small(size));
	}
	else if (size > SMALL_MAX_ALLOC)
	{
//		write(1, "toto6-", 6);
		return (malloc_large(size));
	}
	return (NULL);
}
