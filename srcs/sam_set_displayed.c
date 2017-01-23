/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_set_displayed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 10:49:03 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 11:11:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t		sam_set_displayed(const size_t ptr)
{
	size_t			i;
	t_list_alloc	*list;

	if ((list = sam_get_list()) == NULL)
		return (0);
	i = 0;
//	sam_itoa_base_stack(ptr, "0123456789ABCDEF");
	while (list != NULL)
	{
		while (i < ALLOC_TAB)
		{
			if ((list->ptr)[i] == ptr)
			{
				(list->disp)[i] = SAM_DISP;
				return (ptr);
			}
			i++;
	//		ft_putendl("ici");
		}
		i = 0;
		list = list->next;
	}
	return (0);
}
