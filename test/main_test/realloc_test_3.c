/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 12:31:16 by cledant           #+#    #+#             */
/*   Updated: 2017/01/21 14:50:56 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#define SIZE 128

int		main (void)
{
	char	**base;
	size_t	i;
	void	*ptr;

	write(1, "========== DEBUG ==========\n",28);
	i = 0;
	base = (char **)malloc(sizeof(char *) * SIZE);
	while (i < SIZE)
	{
		base[i] = (char *)malloc(sizeof(char) * 65);
		(*base)[i] = 42;
		i++;
	}
	i = 0;
	ptr = base;
	while (i < SIZE)
	{
		base[i] = realloc(base[i], 4000);
		(*base)[i] = 42;
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		free(base[i]);
		i++;
	}
	free(base);
	return (0);
}
