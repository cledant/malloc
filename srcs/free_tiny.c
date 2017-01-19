/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tiny.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:23:04 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 18:26:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_tiny(const size_t addr)
{
	t_tiny			*header;
	short int		user_id;
	short int		alloc_id;
	size_t			nb_alloc;

	header = NULL;
	user_id = INVALID_USER;
	alloc_id = INVALID_ALLOC;
	nb_alloc = 0;
	if ((header = free_seek_header_for_addr_tiny(addr)) == NULL)
		return (FREE_NOP);
	if (free_is_valid_alloc_tiny(header, addr, &user_id, &alloc_id) == FREE_NOP)
		return (FREE_NOP);
	if (free_seek_nb_alloc_tiny(header, user_id, alloc_id, &nb_alloc)
			== FREE_NOP)
		return (FREE_NOP);
	if ((free_deallocate_tiny(header, user_id, alloc_id, nb_alloc)) == FREE_NOP)
		return (FREE_NOP);
	if (header->used_alloc == 0 && header->prev != NULL)
		free_check_to_delete_header_tiny(header);
	return (FREE_OK);
}
