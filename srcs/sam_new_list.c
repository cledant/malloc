/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_new_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:13:42 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 18:43:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_list_alloc		*sam_new_list(void)
{
	t_list_alloc	*header;

	if ((header = (t_list_alloc *)mmap(NULL, PAGESIZE, PROT_READ | PROT_WRITE,
			MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
		return (NULL);
	header->prev = NULL;
	header->next = NULL;
	header->max = ALLOC_TAB;
	header->used = 0;
	ft_bzero(header->ptr, sizeof(size_t) * ALLOC_TAB);
	ft_bzero(header->size, sizeof(size_t) * ALLOC_TAB);
	ft_bzero(header->disp, sizeof(char) * ALLOC_TAB);
	ft_bzero(header->type, sizeof(char) * ALLOC_TAB);
	return (header);
}
