/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_tiny.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 14:35:00 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 14:41:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*malloc_tiny(size_t size)
{
	t_large		*header;
	void		*ptr;

	if ((header = malloc_get_tiny()) == NULL)
		return (NULL);

	return (ptr);
}
