/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_get_userid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 15:59:54 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 10:13:55 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

short int		malloc_get_userid(const char *index, const t_type type)
{
	short int	i;
	short int	max;

	i = 0;
	if (type == LARGE)
		return (INVALID_USER);
	max = (type == TINY) ? TINY_TAB : SMALL_TAB;
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
