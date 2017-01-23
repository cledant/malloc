/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reallocf_wrapper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:34:15 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 19:35:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*reallocf_wrapper(void *old_ptr, void *new_ptr)
{
	if (new_ptr == NULL)
	{
		free(old_ptr);
		return (NULL);
	}
	return (new_ptr);
}
