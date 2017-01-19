/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_deallocate_tiny.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 15:22:25 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 15:23:39 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_deallocate_tiny(t_tiny *header, const short int user_id,
			const short int alloc_id, const size_t nb_alloc)
{
	return (FREE_NOP);
}
