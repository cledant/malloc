/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_new_large.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 13:20:25 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 19:39:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_large		*malloc_new_large(void)
{
	t_large		*header;

//	write(1, "bbb1-", 5);
	if ((header = (t_large *)mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	header->prev = NULL;
	header->next = NULL;
	header->max_alloc = LARGE_TAB;
	header->used_alloc = 0;
//	write(1, "bbb2-", 5);
	ft_bzero(header->size, sizeof(size_t) * LARGE_TAB);
//	write(1, "bbb3-", 5);
	ft_bzero(header->mem, sizeof(size_t) * LARGE_TAB);
//	write(1, "bbb4-", 5);
	return (header);
}
