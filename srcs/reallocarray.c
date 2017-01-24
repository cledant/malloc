/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:20:11 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 15:37:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*reallocarray(void *ptr, size_t count, size_t size)
{
	ft_putendl("reallocarry");
	if (count >= SIZE_T_MULT_OVERFLOW && size >= SIZE_T_MULT_OVERFLOW)
		return (NULL);
	return (realloc(ptr, count * size));
}
