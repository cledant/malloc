/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_check_to_delete_header_small.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:53:55 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 17:54:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

inline void		free_check_to_delete_header_small(t_small *header)
{
	if (header->next == NULL && header->prev->used_alloc
			<= SMALL_MIN_USED_IN_ADJ)
		free_delete_small(header);
	else if (header->prev->used_alloc <= SMALL_MIN_USED_IN_ADJ
			|| header->next->used_alloc <= SMALL_MIN_USED_IN_ADJ)
		free_delete_small(header);
}
