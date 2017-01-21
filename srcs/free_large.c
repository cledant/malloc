/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 18:54:35 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 11:55:04 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		free_large(const size_t addr)
{
	t_large		*header;

	ft_putendl("FREE-L");
	if ((header = malloc_get_large()) == NULL)
		return (FREE_NOP);
	while (header != NULL)
	{
		if (free_seek_and_deallocate_large(addr, header) == FREE_OK)
		{
			ft_putendl("FREE-L-OK");
			return (FREE_OK);
		}
		header = header->next;
	}
	ft_putendl("FREE-L-FAILED");
	return (FREE_NOP);
}
