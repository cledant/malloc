/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_seek_nb_alloc_tiny.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:48:23 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 13:51:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_seek_nb_alloc_tiny(const t_tiny *header, const short int user_id,
			const short int alloc_id, size_t *nb_alloc)
{
	return (FREE_NOP);
}
