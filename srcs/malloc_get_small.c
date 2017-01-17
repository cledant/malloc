/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:34:32 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 12:35:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_small		*malloc_get_small(void)
{
	static t_small	*small = NULL;
	static int		init = 0;

	if (init == 0)
	{
		if ((small = malloc_new_small()) == NULL)
			return (NULL);
		init = 1;
	}
	return (small);
}
