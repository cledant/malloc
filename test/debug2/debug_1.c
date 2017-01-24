/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:24:39 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 11:14:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "malloc.h"

int		main(void)
{
	int		i;
	char	*addr;

	show_alloc_mem();
	ft_putendl("================");
	i = 0;
	while (i < 8192)
	{
		addr = (char *)malloc(32);
		addr[0] = 42;
		i++;
	}
	i = 0;
	while (i < 8192)
	{
		addr = (char *)malloc(4096);
		addr[0] = 42;
		i++;
	}
	i = 0;
	while (i < 8192)
	{
		addr = (char *)malloc(8192);
		addr[0] = 42;
		i++;
	}
	ft_putendl("================");
	show_alloc_mem();
	return (0);
}
