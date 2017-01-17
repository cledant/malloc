/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_new_tiny.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 12:01:09 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 12:55:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_tiny		*malloc_new_tiny(void)
{
	t_tiny		*header;
	void		*memory;

	if ((header = (t_tiny *)mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) = MAP_FAILED)
		return (NULL);
	if ((memory = mmap(NULL, 4 * PAGESIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
	{
		munmap(header, PAGESIZE);
		return (NULL);
	}
	header->prev = NULL;
	header->next = NULL;
	header->max_alloc = TINY_TAB;
	header->used_alloc = 0;
	ft_bzero(header->state, sizeof(unsigned short int) * TINY_TAB);
	ft_bzero(header->index, sizeof(char) * TINY_TAB);
	header->mem = memory;
	return (header);
}
