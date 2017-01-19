/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:39:03 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 17:42:27 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_small(const size_t addr)
{
	t_small			*header;
	short int		user_id;
	short int		alloc_id;
	size_t			nb_alloc;

	header == NULL;
	user_id = INVALID_USER;
	alloc_id = INVALID_ALLOC;
	nb_alloc = 0;
	if ((header = free_seek_header_for_addr_small(addr)) == NULL)
		return (FREE_NOP);
	if (free_is_valid_alloc_small(header, addr, &user_id, &alloc_id)
			== FREE_NOP)
		return (FREE_NOP);
	if (free_seek_nb_alloc_small(header, user_id, alloc_id, &nb_alloc)
			== FREE_NOP)
		return (FREE_NOP);
	if ((free_deallocate_small(header, user_id, alloc_id, nb_alloc))
			== FREE_NOP)
		return (FREE_NOP);
	if (header->used_alloc == 0 && header->prev != NULL)
		free_check_to_delete_header_small(header);
	return (FREE_OK);
}
