/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_large.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 19:57:27 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 09:18:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_large(const size_t size)
{
	t_large		*header;
	size_t		nb_alloc;

	nb_alloc = 0;
	if ((header = malloc_get_large()) == NULL)
		return (NULL);
	if ((nb_alloc = malloc_get_number_alloc(size, PAGESIZE, LARGE)) == 0)
		return (NULL);
}
