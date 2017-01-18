/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_allocate_large.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:58:44 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 19:49:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_allocate_large(t_large *header, const size_t nb_alloc)
{
	void	*ptr_mem;
	size_t	i;

	i = 0;
	while (i < LARGE_TAB)
	{
		if ((header->size)[i] == NOT_USED)
			break ;
		i++;
	}
	if ((header->size)[i] != NOT_USED)
		return (NULL);
//	write(1, "kakaka1-", 8);
	if ((ptr_mem = mmap(NULL, nb_alloc * PAGESIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
//	write(1, "kakaka2-", 8);
//	ft_memcpy(header->mem + i * sizeof(void *), &ptr_mem, sizeof(void *));
	(header->mem)[i] = (size_t)ptr_mem;
//	write(1, "kakaka3-", 8);
	(header->size)[i] = nb_alloc * PAGESIZE;
	(header->used_alloc)++;
//	write(1, "kakaka4-", 8);
	return (ptr_mem);
}
