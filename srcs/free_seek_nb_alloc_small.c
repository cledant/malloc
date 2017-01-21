/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_seek_nb_alloc_small.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:50:16 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 15:00:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_seek_nb_alloc_small(const t_small *header,
			const short int user_id, const short int alloc_id,
			size_t *nb_alloc)
{
	size_t	i;

	i = alloc_id;
	*nb_alloc = 0;
	while (i < SMALL_TAB && (header->state)[i] == user_id)
	{
		(*nb_alloc)++;
		i++;
	}
	if (*nb_alloc > SMALL_MAX_NB_PER_ALLOC)
		return (FREE_NOP);
	return (FREE_OK);
}
