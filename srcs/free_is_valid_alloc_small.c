/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_is_valid_alloc_small.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 17:46:01 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 17:48:57 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_is_valid_alloc_small(const t_small *header, const size_t addr,
			short int *user_id, short int *alloc_id)
{
	short int	i;
	size_t		addr;
	size_t		mem_addr

	i = 0;
	while (i < SMALL_TAB)
	{
		mem_addr = header->addr + i * SMALL_MIN_ALLOC;
		if (mem_addr == addr)
			break ;
		i++;
	}
	if (mem_addr != addr)
		return (FREE_NOP);
	if ((*user_id = state[i]) == 0)
		return (FREE_NOP);
	*alloc_id = i;
	if (i == 0)
		return (FREE_OK);
	else if (state[i - 1] != *user_id)
		return (FREE_OK)
	return (FREE_NOP);
}
