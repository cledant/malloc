/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:41:31 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 15:34:52 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		malloc_init(char *init)
{
	if (malloc_getpagesize() != 4096)
		return (-1);
	if (malloc_init_tiny() == -1)
		return (-1);
	if (malloc_init_small() == -1)
		return (-1);
	*init = 1;
	return (0);
}
