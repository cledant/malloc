/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 12:31:16 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 15:19:10 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define SIZE 2048

int		main (void)
{
	char	**base;
	char	**base2;
	size_t	i;

	write(1, "========== DEBUG ==========\n",28);
	i = 0;
	base = (char **)malloc(sizeof(char *) * SIZE);
	while (i < SIZE)
	{
		base[i] = (char *)malloc(sizeof(char) * 4096);
		(*base)[i] = 42;
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		base[i] = realloc(base[i], 128);
		(*base)[i] = 42;
		i++;
	}
	i = 0;
	base2 = (char **)malloc(sizeof(char *) * SIZE);
	while (i < SIZE)
	{
		base2[i] = (char *)malloc(sizeof(char) * 128);
		(*base2)[i] = 42;
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		base2[i] = realloc(base2[i], 128);
		(*base2)[i] = 42;
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		free(base[i]);
		i++;
	}
	free(base);
	i = 0;
	while (i < SIZE)
	{
		free(base2[i]);
		i++;
	}
	free(base2);
	return (0);
}
