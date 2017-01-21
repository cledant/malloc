/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_get_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:06:36 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 17:11:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_list_alloc	*sam_get_list(void)
{
	static t_list_alloc		*list = NULL;
	static char				init = 0;

	if (list == NULL)
	{
		if ((list = sam_new_list()) == NULL)
			return (NULL);
		init = 1;
	}
	return (list);
}
