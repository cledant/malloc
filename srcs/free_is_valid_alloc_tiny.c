/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_is_valid_alloc_tiny.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 12:42:07 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 18:29:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_is_valid_alloc_tiny(const t_tiny *header, const size_t addr,
			short int *user_id, short int *alloc_id)
{
	short int	i;
	size_t		mem_addr;

	i = 0;
	while (i < TINY_TAB)
	{
		mem_addr = (size_t)header->mem + i * TINY_MIN_ALLOC;
		if (mem_addr == addr)
			break ;
		i++;
	}
	if (mem_addr != addr)
		return (FREE_NOP);
	if ((*user_id = (header->state)[i]) == 0)
		return (FREE_NOP);
	*alloc_id = i;
	if (i == 0)
		return (FREE_OK);
	else if ((header->state)[i - 1] != *user_id)
		return (FREE_OK);
	return (FREE_NOP);
}
