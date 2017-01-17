/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_tiny.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 16:05:22 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 12:34:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_tiny	*malloc_get_tiny(void)
{
	static t_tiny	*tiny = NULL;
	static int		init = 0;

	if (init == 0)
	{
		if ((tiny = malloc_new_tiny()) == NULL)
			return (NULL);
		init = 1;
	}
	return (tiny);
}
