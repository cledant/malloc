/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_clean_memory.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 21:09:26 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 10:36:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_clean_memory(void)
{
	t_list_alloc	*list;

	if ((list = sam_get_last_list()) == NULL)
		return ;
	while (list != NULL)
	{
		if (list->prev != NULL)
			munmap(list, PAGESIZE);
		list = list->prev;
	}
}
