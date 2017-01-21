/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 12:12:51 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 12:14:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*reallocarray(void *ptr, size_t count, size_t size)
{
	ft_putendl("REALLOCARRAY\n");
	return (realloc(ptr, count * size));
}
