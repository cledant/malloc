/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_new_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:13:42 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 18:41:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		sam_reset_list(void)
{
	t_list_alloc	*list;

	if ((list = sam_get_list()) == NULL)
		return (SAM_NOP);
	list->prev = NULL;
	list->next = NULL;
	list->used = 0;
	list->max = ALLOC_TAB;
	ft_bzero(list->size, sizeof(size_t) * ALLOC_TAB);
	ft_bzero(list->ptr, sizeof(size_t) * ALLOC_TAB);
	ft_bzero(list->disp, sizeof(char) * ALLOC_TAB);
	ft_bzero(list->type, sizeof(char) * ALLOC_TAB);
	return (SAM_OK);
}
