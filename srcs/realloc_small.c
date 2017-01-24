/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:10:27 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 15:15:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc_small(t_small *header, void *ptr, const size_t new_size)
{
	short int	user_id;
	short int	alloc_id;
	size_t		cur_nb_alloc;
	size_t		new_nb_alloc;

	if (free_is_valid_alloc_small(header, (size_t)ptr, &user_id, &alloc_id)
			== FREE_NOP)
		return (NULL);
	if (free_seek_nb_alloc_small(header, user_id, alloc_id, &cur_nb_alloc)
			== FREE_NOP)
		return (NULL);
	if ((new_nb_alloc = malloc_get_number_alloc(new_size,
			SMALL_MIN_ALLOC, SMALL)) == 0)
		return (NULL);
	if (cur_nb_alloc == new_nb_alloc)
		return (ptr);
	else if (cur_nb_alloc > new_nb_alloc)
	{
		realloc_change_size_small(header, alloc_id, cur_nb_alloc, new_nb_alloc);
		return (ptr);
	}
	else
		return (realloc_new_ptr(ptr, new_size,
					cur_nb_alloc * SMALL_MIN_ALLOC));
}
