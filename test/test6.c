/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test6.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:58:25 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 19:07:54 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <stdlib.h>

int		main(void)
{
	char	**ptr;
	size_t	i;

	i = 0;
	show_alloc_mem_ex();
	ptr = (char **)malloc(sizeof(char *) * 20);
	while (i < 4)
	{
		ptr[i] = (char *)malloc(64 * sizeof(char));
		strcpy(ptr[i], "Coucou");
		i++;
	}
	ft_putendl("===============================");
	show_alloc_mem_ex();
	free(ptr[1]);
	free(ptr[2]);
	ft_putendl("===============================");
	show_alloc_mem_ex();
	while (i < 12)
	{
		ptr[i] = (char *)malloc(16 * sizeof(char));
		strcpy(ptr[i], "Coucou");
		i++;
	}
	ft_putendl("===============================");
	show_alloc_mem_ex();
	return (0);
}
