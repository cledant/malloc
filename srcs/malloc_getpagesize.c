/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_getpagesize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:10:16 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 14:12:17 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

inline int		malloc_getpagesize(void)
{
	static int		pagesize = 0;

	if (pagesize == 0)
		pagesize = getpagesize();
	return (pagesize);
}
