/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_allocate_tiny.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:49:01 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 19:28:33 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_allocate_tiny(t_tiny *header, const size_t nb_alloc,
			const short int user_id, const short int alloc_id)
{
	short int	i;
	void		*ptr;

	i = 0;
	header->index[user_id - 1] = USED;
	while (i < nb_alloc)
	{
		header->state[alloc_id + i] = user_id;
		i++;
	}
	ptr = header->mem + alloc_id * TINY_MIN_ALLOC;
	return (ptr);
}
