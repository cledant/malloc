/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 16:24:39 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 18:09:28 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		main(void)
{
	int		i;
	char	*addr;

	i = 0;
	while (i < 2048)
	{
		addr = (char *)malloc(4096);
		addr[0] = 42;
		i++;
	}
	return (0);
}
