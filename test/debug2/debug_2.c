/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:24:39 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 11:58:20 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "malloc.h"

int		main(void)
{
	int		i;
	char	**addr;

	show_alloc_mem();
	addr = (char **)malloc(sizeof(char *) * 8192 * 4);
	ft_putendl("================");
	i = 0;
	while (i < 8192)
	{
		addr[i] = (char *)malloc(64);
		strcpy((addr)[i], "Coucou");
		i++;
	}
	while (i < 8192 * 2)
	{
		addr[i] = (char *)malloc(4096);
		strcpy((addr)[i], "NYAHAHAHAHAHA");
		i++;
	}
	while (i < 8192 * 3)
	{
		addr[i] = (char *)malloc(8192);
		strcpy((addr)[i], "MEGA MEGA MEGA MEGA&&&&&&");
		i++;
	}
	ft_putendl("================");
	i = 0;
	while (i < 8192 * 3)
	{
		ft_putendl((addr)[i]);
		free((addr)[i]);
		i++;
	}
	free(addr);
	show_alloc_mem();
	return (0);
}
