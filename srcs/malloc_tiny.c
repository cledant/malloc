/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tiny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:35:00 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 19:06:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_tiny(const size_t size)
{
	t_large			*header;
	size_t			nb_alloc;
	short int		user_id;
	short int		alloc_id;
	void			*ptr;

	user_id = INVALID_USER;
	alloc_id = INVALID_ALLOC;
	if ((header = malloc_get_available_tiny()) == NULL)
		return (NULL);
	if ((nb_alloc = malloc_get_number_alloc(size, TINY_MIN_ALLOC, TINY)) == 0)
		return (NULL);
	if ((user_id = malloc_get_userid(header->index, TINY)) == INVALID_USER)
		return (NULL);
	if ((alloc_id = malloc_get_allocid(header->state, nb_alloc, TINY))
			== INVALID_ALLOC)
		return (NULL);
	ptr = malloc_allocate_tiny(header, nb_alloc, user_id, alloc_id);
	return (ptr);
}
