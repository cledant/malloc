/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 09:18:14 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 09:23:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		main(void)
{
	size_t max = 0;

	max--;
	printf("max = %lu\n", max);
	char *test;
	test = (char *)malloc(sizeof(char) * max);
	if (test == NULL)
	{
		printf("PTR NULL\n");
		return (0);
	}
	test[0] = 42;
	return (0);
}
