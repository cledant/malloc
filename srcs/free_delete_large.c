/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_delete_large.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 19:50:44 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 19:51:50 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free_delete_large(t_large *header)
{
	t_large		*cur_prev;
	t_large		*cur_next;

	cur_prev = header->prev;
	cur_next = header->next;
	if (cur_prev != NULL)
		cur_prev->next = cur_next;
	if (cur_next != NULL)
		cur_next->prev = cur_prev;
	munmap(header, PAGESIZE);
}
