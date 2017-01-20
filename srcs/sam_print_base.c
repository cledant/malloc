/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_print_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 18:44:40 by cledant           #+#    #+#             */
/*   Updated: 2017/01/20 19:10:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	sam_print_base(size_t num, char *base)
{
	char	display[256];
	size_t	size_base;
	size_t	i;

	if (num == 0)
		return (ft_putchar('0'));
	if ((size_base = ft_strlen(base)) == 1)
		return ;
	ft_bzero(display, 256);
	i = 0;
	while (num != 0)
	{
		display[i] = base[num % size_base];
		num /= size_base;
		i++;
	}
	while (i != 0)
	{
		ft_putchar(display[i - 1]);
		i--;
	}
}
