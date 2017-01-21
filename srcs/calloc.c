/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 09:58:33 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 11:35:49 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t count, size_t size)
{
	void	*ptr;

	ft_putstr("CALLOC\n");
/*	sam_print_base(count, "0123456789");
	ft_putstr(" : ");
	sam_print_base(size, "0123456789");
	ft_putstr(" = ");
	sam_print_base(size * count, "0123456789");
	ft_putendl("");*/
	if ((ptr = (void *)malloc(count * size)) == NULL)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}
