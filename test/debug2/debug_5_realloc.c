/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:24:39 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 13:08:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "malloc.h"

int		main(void)
{
	int		i;
	char	**addr;
	void	*old;

	show_alloc_mem();
	addr = (char **)malloc(sizeof(char *) * 8192 * 4);
	ft_putendl("1================");
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
	show_alloc_mem();
	ft_putendl("2================");
	i = 0;
	while (i < 8192)
	{
		old = addr[i];
		addr[i] = (char *)realloc(addr[i], 4096);
		strcpy((addr)[i], "AA");
		free(old);
		i++;
	}
	ft_putendl("2-1");
	while (i < 8192 * 2)
	{
		ft_putendl("2-1-1");
		old = addr[i];
		ft_putendl("2-1-2");
		addr[i] = (char *)realloc(addr[i], 8192);
		ft_putendl("2-1-3");
		strcpy((addr)[i], "TEST");
		ft_putendl("2-1-4");
		free(old);
		ft_putendl("2-1-5");
		i++;
	}

	ft_putendl("2-2");
	while (i < 8192 * 3)
	{
		old = addr[i];
		addr[i] = (char *)realloc(addr[i], 12288);
		strcpy((addr)[i], "AHHHHHHHHHHHH");
		free(old);
		i++;
	}
	ft_putendl("2-3");
	show_alloc_mem();
	ft_putendl("3================");
	i = 0;
	while (i < 8192 * 3)
	{
		ft_putendl((addr)[i]);
		free((addr)[i]);
		i++;
	}
	free(addr);
	ft_putendl("4================");
	show_alloc_mem();
	return (0);
}
