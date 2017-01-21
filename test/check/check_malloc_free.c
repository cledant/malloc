/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_malloc_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:34:38 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 10:39:48 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		main(void)
{
	char	*toto;

	toto = (char *)malloc(32);
	printf("OK 1\n");
	free(toto + 10);
	printf("OK 2\n");
	return (0);
}
