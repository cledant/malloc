/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:00:38 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 11:15:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include "libft.h"
# include "malloc_function.h"

# define PAGESIZE 4096
# define TINY_MIN_ALLOC 16
# define TINY_MAX_ALLOC 64
# define TINY_TAB 1024
# define SMALL_MIN_ALLOC 128
# define SMALL_MAX_ALLOC 4096
# define SMALL_TAB 4096
# define LARGE_MIN_ALLOC 8192
# define LARGE_TAB 254
# define LARGE_PREALLOC 128

# define NOT_USED 0
# define USED 1
# define INVALID_USER -1
# define INVALID_ALLOC -1
# define INVALID_LARGE_ALLOC 255

#endif
