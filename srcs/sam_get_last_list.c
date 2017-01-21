/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_get_last_list.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 18:18:29 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 18:20:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_list_alloc	*sam_get_last_list(void)
{
	t_list_alloc	*list;

	if ((list = sam_get_list()) == NULL)
		return (NULL);
	while (list->next != NULL)
		list = list->next;
	return (list);
}
