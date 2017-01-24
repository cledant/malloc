/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:59:25 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 15:34:34 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	if (count >= SIZE_T_MULT_OVERFLOW && size >= SIZE_T_MULT_OVERFLOW)
		return (NULL);
	if ((ptr = malloc(count * size)) == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	ft_putendl("calloc");
	return (ptr);
}
