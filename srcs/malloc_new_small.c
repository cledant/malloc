/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_new_small.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:36:21 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 13:25:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_small		*malloc_new_small(void)
{
	t_small		*header;
	void		*memory;

	if ((header = (t_small *)mmap(NULL, 4 * PAGESIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	if ((memory = mmap(NULL, 128 * PAGESIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
	{
		munmap(header, PAGESIZE);
		return (NULL);
	}
	header->prev = NULL;
	header->next = NULL;
	header->max_alloc = SMALL_TAB;
	header->used_alloc = 0;
	ft_bzero(header->state, sizeof(unsigned short int) * SMALL_TAB);
	ft_bzero(header->index, sizeof(char) * SMALL_TAB);
	header->mem = memory;
	return (header);
}
