/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_add_new_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:44:59 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 18:47:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		sam_add_new_list(t_list_alloc *list)
{
	t_list_alloc	*new;

	if ((new = sam_new_list()) == NULL)
		return (SAM_NOP);
	list->next = new;
	new->prev = list;
	return (SAM_OK);
}
