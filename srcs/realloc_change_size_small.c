/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_change_size_small.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 15:16:49 by cledant           #+#    #+#             */
/*   Updated: 2017/01/20 15:17:40 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

inline void		realloc_change_size_small(t_small *header,
					const short int alloc_id,
					const size_t cur_nb_alloc, const size_t new_nb_alloc)
{
	short int	i;

	i = alloc_id + (short int)(new_nb_alloc);
	while (i < SMALL_TAB && i < alloc_id + (short int)cur_nb_alloc)
	{
		(header->state)[i] = NOT_USED;
		i++;
	}
}
