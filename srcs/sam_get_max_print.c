/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_get_max_print.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 20:13:43 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 20:16:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "malloc.h"

size_t		sam_get_max_print(void);
{
	size_t			count;
	t_alloc_list	*list;

	if ((list = sam_get_list()) == NULL)
		return (0);
	count = 0;
	while (list != NULL)
	{
		count += list->used;
		list = list->next;
	}
	return (count);
}
