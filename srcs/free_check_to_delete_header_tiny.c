/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_check_to_delete_header_tiny.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:47:34 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 19:48:59 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

inline void		free_check_to_delete_header_tiny(t_tiny *header)
{
	if (header->next == NULL && header->prev->used_alloc
			<= TINY_MIN_USED_IN_ADJ)
		free_delete_tiny(header);
	else if (header->prev->used_alloc <= TINY_MIN_USED_IN_ADJ
			|| (header->next != NULL && header->next->used_alloc
				<= TINY_MIN_USED_IN_ADJ))
		free_delete_tiny(header);
}
