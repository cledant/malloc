/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_new_large.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:20:25 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 13:25:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_large		*malloc_new_large(void)
{
	t_large		*header;
	void		*memory;

	if ((header = (t_large *)mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	header->prev = NULL;
	header->next = NULL;
	header->max_alloc = LARGE_TAB;
	header->used_alloc = 0;
	ft_bzero(header->size, sizeof(size_t) * LARGE_TAB);
	ft_bzero(header->memory, sizeof(void *) * LARGE_TAB);
	return (header);
}
