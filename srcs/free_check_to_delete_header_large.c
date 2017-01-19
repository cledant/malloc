/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_check_to_delete_header_large.c                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:40:09 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 19:48:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

inline void		free_check_to_delete_header_large(t_large *header)
{
	if (header->next == NULL && header->prev->used_alloc
			<= LARGE_MIN_USED_IN_ADJ)
		free_delete_large(header);
	else if (header->prev->used_alloc <= LARGE_MIN_USED_IN_ADJ
			|| (header->next != NULL && header->next->used_alloc
				<= LARGE_MIN_USED_IN_ADJ))
		free_delete_large(header);
}
