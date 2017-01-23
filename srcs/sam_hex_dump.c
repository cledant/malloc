/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sam_hex_dump.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 21:24:46 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 23:20:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

inline static void		hex_convert(void *ptr, const size_t size)
{
	size_t		i;
	char		nbr;

	i = 0;
	nbr = 0;
	while (i < size)
	{
		ft_memcpy(&nbr, ptr, sizeof(char));
		if ((unsigned char)nbr < 16)
			ft_putchar('0');
		sam_itoa_base_stack((unsigned char)nbr, "0123456789ABCDEF");
		ft_putchar(' ');
		if ((i + 1) % 64 == 0)
			ft_putendl("");
		i++;
		ptr++;
	}
	if ((i + 1) % 64 != 0)
		ft_putendl("");
}

inline static void		dump_printable(void *ptr, const size_t size)
{
	size_t		i;
	char		nbr;

	i = 0;
	nbr = 0;
	while (i < size)
	{
		ft_memcpy(&nbr, ptr, sizeof(char));
		if (ft_isprint((unsigned char)nbr) == 1)
			ft_putchar((unsigned char)nbr);
		else
			ft_putchar('.');
		if ((i + 1) % 64 == 0)
			ft_putendl("");
		i++;
		ptr++;
	}
	if ((i + 1) % 64 != 0)
		ft_putendl("");
}

void					sam_hex_dump(void *ptr, const size_t size)
{
	ft_putendl("--Hex dump :");
	ft_putchar('\n');
	hex_convert(ptr, size);
	ft_putchar('\n');
	ft_putendl("--Printable dump :");
	ft_putchar('\n');
	dump_printable(ptr, size);
}
