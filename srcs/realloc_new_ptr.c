/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_new_ptr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:27:30 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 15:13:13 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc_new_ptr(void *ptr, const size_t new_size,
			const size_t old_size)
{
	void	*new_ptr;

	if ((new_ptr = (void *)malloc(new_size)) == NULL)
		return (NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	return (new_ptr);
}
