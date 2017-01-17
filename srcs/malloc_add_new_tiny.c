/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_add_new_tiny.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 17:02:44 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 17:36:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		malloc_add_new_tiny(t_tiny *header)
{
	t_tiny	*new;

	if ((new = malloc_new_tiny()) == NULL)
		return (-1);
	header->next = new;
	new->previous = header;
	return (0);
}
