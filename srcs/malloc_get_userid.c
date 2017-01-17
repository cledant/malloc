/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_userid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:59:54 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 16:16:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

unsigned short int		malloc_get_userid(const char *index, const t_type type)
{
	unsigned short int	i;
	unsigned short int	max;

	i = 0;
	if (type == LARGE)
		return (INVALID_USER);
	else if (type == TINY)
		max = TINY_TAB;
	else
		max = SMALL_TAB;
	while (i < max)
	{
		if (index[i] == NOT_USED)
			break ;
		i++;
	}
	if (i == max)
		return (INVALID_USER);
	return (i + 1);
}
