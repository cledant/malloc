/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:34:32 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 13:53:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_small		*malloc_get_large(void)
{
	static t_large	*large = NULL;
	static int		init = 0;

	if (init == 0)
	{
		if ((large = malloc_new_large()) == NULL)
			return (NULL);
		if (malloc_prealloc_large(&large) != 0)
			return (NULL);
		init = 1;
	}
	return (large);
}
