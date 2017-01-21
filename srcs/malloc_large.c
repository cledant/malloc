/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:57:27 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 12:00:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_large(const size_t size)
{
	t_large			*header;
	void			*ptr;
	size_t			nb_alloc;

	if ((nb_alloc = malloc_get_number_alloc(size, PAGESIZE, LARGE)) == 0)
		return (NULL);
	if ((header = malloc_get_available_large()) == NULL)
		return (NULL);
	ptr = malloc_allocate_large(header, nb_alloc);
	ft_putendl("ALLOC_ADR : ");
	sam_print_base((size_t)ptr, "0123456789");
	ft_putendl("");
	return (ptr);
}
