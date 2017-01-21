/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 08:56:29 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 09:49:08 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	size_t	res;
	size_t	alloc = 4096;

	size_t test = 0;
	printf("min size_t = %lu\n", test);
	test--;
	printf("max size_t = %lu\n", test);
	test -= 4096 - 1;
	printf("limite allocation = %lu\n", test);
	res = test / alloc;
	printf("nb alloc = %lu\n", res);
	size_t res_t = res * 4096;
	printf("nb alloc * 4096 en size_t = %lu\n", res_t);
	size_t reste = test % 4096;
	printf("doit pas etre diff de 0 = %lu\n", reste);
	return (0);
}
