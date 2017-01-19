/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:54:35 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 19:16:51 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_large(const size_t size)
{
	t_large		*header;

	header == NULL;
	if ((header == malloc_get_large()) == NULL)
		return (FREE_NOP);
	while (header != NULL)
	{
		if (free_seek_and_disallocate_large(addr, header) == FREE_OK)
			return (FREE_OK);
		header = header->next;
	}
	return (FREE_NOP);
}
