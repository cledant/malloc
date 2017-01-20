/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_tiny.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:03:27 by cledant           #+#    #+#             */
/*   Updated: 2017/01/20 14:52:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc_tiny(t_tiny *header, const void *ptr, const size_t new_size)
{
	short int	user_id;
	short int	alloc_id;
	size_t		cur_nb_alloc;
	size_t		new_nb_alloc;

	if (free_is_valid_alloc_tiny(header, (size_t)ptr, &user_id, &alloc_id)
			== FREE_NOP)
		return (NULL);
	if (free_seek_nb_alloc_tiny(header, user_id, alloc_id, &cur_nb_alloc)
			== FREE_NOP)
		return (NULL);
	if ((new_nb_alloc = malloc_get_number_alloc(new_size,
			TINY_MIN_ALLOC, TINY)) == 0)
		return (NULL);
	if (cur_nb_alloc == new_nb_alloc)
		return (ptr);
	else if (cur_nb_alloc > new_nb_alloc)
	{
		realloc_change_size_tiny(header, alloc_id, cur_nb_alloc, new_nb_alloc);
		return (ptr);
	}
	else
		return (realloc_new_ptr(ptr, new_size));
}
