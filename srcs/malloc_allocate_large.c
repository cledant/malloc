/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_allocate_large.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 11:58:44 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 12:32:58 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_allocate_large(t_large *header, const size_t nb_alloc)
{
	void	*ptr_mem;
	void	*ptr_alloc;
	size_t	alloc_id;
	size_t	i;

	i = 0;
	alloc_id = 0;
	while (i < LARGE_TAB)
	{
		if ((header->size)[i] == NOT_USED)
			break ;
		i++;
	}
	if ((header->size)[i] != NOT_USED)
		return (NULL);
	if ((ptr_mem = mmap(NULL, nb_alloc * PAGESIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	(header->mem)[i * sizeof(void *)] = ptr_mem;
	(header->size)[i] = nb_alloc * PAGESIZE;
	return (ptr_mem);
}
