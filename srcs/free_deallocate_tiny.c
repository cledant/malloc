/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_deallocate_tiny.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:22:25 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 18:30:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_deallocate_tiny(t_tiny *header, const short int user_id,
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
