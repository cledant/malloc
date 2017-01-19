/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_delete_small.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:19:26 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 18:20:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free_delete_small(t_small *header)
{
	t_small		*cur_prev;
	t_small		*cur_next;

	cur_prev = header->prev;
	cur_next = header->next;
	if (cur_prev != NULL)
		cur_prev->next = cur_next;
	if (cur_next != NULL)
		cur_next->prev = cur_prev;
	munmap(header->mem, 128 * PAGESIZE);
	munmap(header, 4 * PAGESIZE);
}
