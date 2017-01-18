/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_add_new_large.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:52:13 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 11:53:05 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		malloc_add_new_large(t_large *header)
{
	t_large		*new;

	if ((new = malloc_new_large()) == NULL)
		return (-1);
	header->next = new;
	new->previous = header;
	return (0);
}
