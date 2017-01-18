/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:41:31 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 17:10:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		malloc_init(char *init)
{
//	write(1, "aaa1-", 5);
	if (malloc_getpagesize() != 4096)
		return (-1);
//	write(1, "aaa2-", 5);
	if (malloc_get_tiny() == NULL)
		return (-2);
//	write(1, "aaa3-", 5);
	if (malloc_get_small() == NULL)
		return (-3);
//	write(1, "aaa4-", 5);
	if (malloc_get_large() == NULL)
		return (-4);
//	write(1, "aaa5-", 5);
	*init = 1;
	return (0);
}
