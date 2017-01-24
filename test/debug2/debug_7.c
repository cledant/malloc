/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:24:39 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 15:05:46 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "malloc.h"

int		main(void)
{
	size_t	i;
	char	*addr;

	show_alloc_mem();
	i = 0;
	ft_putendl("================");
	while (i < 200000)
	{
		addr = (char *)malloc(8192);
		addr[0] = 42;
		i++;
	}
	ft_putendl("================");
	show_alloc_mem();
	return (0);
}
