/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 17:13:38 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 18:45:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free(void *ptr)
{
	size_t	addr;

	if (ptr == NULL)
		return ;
	addr = (size_t)ptr;
	if (free_tiny(addr) == FREE_OK)
		return ;
	else if (free_small(addr) == FREE_OK)
		return ;
	else if (free_large(addr) == FREE_OK)
		return ;
}
