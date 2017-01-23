/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:20:11 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 19:22:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*reallocarray(void *ptr, size_t count, size_t size)
{
	if (count >= SIZE_T_MULT_OVERFLOW && size >= SIZE_T_MULT_OVERFLOW)
		return (NULL);
	return (realloc(ptr, count * size));
}
