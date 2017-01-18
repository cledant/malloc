/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_add_new_small.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:42:04 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 15:17:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		malloc_add_new_small(t_small *header)
{
	t_small		*new;

	if ((new = malloc_new_small()) == NULL)
		return (-1);
	header->next = new;
	new->prev = header;
	return (0);
}
