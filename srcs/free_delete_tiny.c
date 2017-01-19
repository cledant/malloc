/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_delete_tiny.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:18:58 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 16:48:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free_delete_tiny(t_tiny *header)
{
	t_tiny	*cur_prev;
	t_tiny	*cur_next;

	cur_prev = header->prev;
	cur_next = header->next;
	if (cur_prev != NULL)
		cur_prev->next = cur_next;
	if (cur_next != NULL)
		cur_next->prev = cur_prev;
	munmap(header->mem, 4 * PAGESIZE);
	munmap(header, PAGESIZE);
}
