/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:24:39 by cledant           #+#    #+#             */
/*   Updated: 2017/01/20 10:06:02 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024)
	{
		addr = (char *)malloc(8000);
		addr[0] = 42;
		free(addr);
		write(1, "toto\n", 5);
		addr[0] = 43;
		write(1, "tata\n", 5);
		i++;
	}
	return (0);
}
