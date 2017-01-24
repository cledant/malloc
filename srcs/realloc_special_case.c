/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_special_case.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 17:35:14 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 17:39:16 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*realloc_special_case(void *ptr)
{
	void	*new_ptr;

	new_ptr = (void *)malloc(0);
	free(ptr);
	return (new_ptr);
}
