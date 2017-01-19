/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_deallocate_small.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:51:46 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 18:32:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_deallocate_small(t_small *header, const short int user_id,
			const short int alloc_id, const size_t nb_alloc)
{
	size_t	i;
	size_t	j;

	i = alloc_id;
	j = 0;
	if ((size_t)header->used_alloc < nb_alloc)
		return (FREE_NOP);
	header->used_alloc -= nb_alloc;
	(header->index)[user_id - 1] = NOT_USED;
	while (i < TINY_TAB && j < nb_alloc)
	{
		(header->state)[i] = NOT_USED;
		i++;
		j++;
	}
	return (FREE_NOP);
}
