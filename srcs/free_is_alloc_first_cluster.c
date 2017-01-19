/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_is_alloc_first_cluster.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:18:07 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 13:24:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_is_alloc_first_cluster(const t_tiny *header,
			const short int user_id, const short int alloc_id)
{
	short int	i;

	while (i < TINY_TAB)
	{
		if ((header->state)[i] == user_id)
			return ((i == alloc_id) ? FREE_OK : FREE_NOP);
	}
	return (FREE_NOP);
}
