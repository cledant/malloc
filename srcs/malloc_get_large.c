/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:34:32 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 15:14:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_large		*malloc_get_large(void)
{
	static t_large	*large = NULL;
	static int		init = 0;

	if (init == 0)
	{
		if ((large = malloc_new_large()) == NULL)
			return (NULL);
		init = 1;
	}
	return (large);
}
