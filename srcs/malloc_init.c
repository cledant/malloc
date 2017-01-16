/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:41:31 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 16:19:09 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		malloc_init(char *init)
{
	if (malloc_getpagesize() != 4096)
		return (-1);
	if (malloc_get_tiny() == NULL)
		return (-2);
	if (malloc_get_small() == NULL)
		return (-3);
	*init = 1;
	return (0);
}
