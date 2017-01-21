/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:39:03 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 11:53:23 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_small(const size_t addr)
{
	t_small			*header;
	short int		user_id;
	short int		alloc_id;
	size_t			nb_alloc;

	ft_putendl("FREE-S");
	header = NULL;
	user_id = INVALID_USER;
	alloc_id = INVALID_ALLOC;
	nb_alloc = 0;
	if ((header = free_seek_header_for_addr_small(addr)) == NULL)
	{
		ft_putendl("FREE-S-1");
		return (FREE_NOP);
	}
	if (free_is_valid_alloc_small(header, addr, &user_id, &alloc_id)
			== FREE_NOP)
	{		
		ft_putendl("FREE-S-2");
		return (FREE_NOP);
	}
	if (free_seek_nb_alloc_small(header, user_id, alloc_id, &nb_alloc)
			== FREE_NOP)
	{
		ft_putendl("FREE-S-3");
		return (FREE_NOP);
	}
	if ((free_deallocate_small(header, user_id, alloc_id, nb_alloc))
			== FREE_NOP)
	{
		ft_putendl("FREE-S-4");
		return (FREE_NOP);
	}
//	if (header->used_alloc == 0 && header->prev != NULL)
//		free_check_to_delete_header_small(header);
	ft_putendl("FREE-S-5");
	return (FREE_OK);
}
