/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_small.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:34:19 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 19:36:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_small(const size_t size)
{
	t_small			*header;
	size_t			nb_alloc;
	short int		user_id;
	short int		alloc_id;
	void			*ptr;

	user_id = INVALID_USER;
	alloc_id = INVALID_ALLOC;
	if ((header = malloc_get_available_small()) == NULL)
		return (NULL);
	if ((nb_alloc = malloc_get_number_alloc(size, SMALL_MIN_ALLOC,
			SMALL)) == 0)
		return (NULL);
	if ((user_id = malloc_get_userid(header->index, SMALL)) == INVALID_USER)
		return (NULL);
	if ((alloc_id = malloc_get_allocid(header->state, nb_alloc, SMALL))
			== INVALID_ALLOC)
		return (NULL);
	ptr = malloc_allocate_small(header, nb_alloc, user_id, alloc_id);
	return (ptr);
}
