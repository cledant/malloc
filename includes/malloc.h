/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:00:38 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 17:59:03 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include "libft.h"
# include "malloc_function.h"
# include "free_function.h"

# define PAGESIZE 4096
# define TINY_MIN_ALLOC 16
# define TINY_MAX_ALLOC 64
# define TINY_MAX_NB_PER_ALLOC 4
# define TINY_MIN_USED_IN_ADJ 820
# define SMALL_MIN_ALLOC 128
# define SMALL_MAX_ALLOC 4096
# define SMALL_MAX_NB_PER_ALLOC 32
# define SMALL_MIN_USED_IN_ADJ 3277
# define LARGE_MIN_ALLOC 8192
# define LARGE_PREALLOC 128

# define NOT_USED 0
# define USED 1
# define INVALID_USER -1
# define INVALID_ALLOC -1
# define INVALID_LARGE_ALLOC 255

# define FREE_OK 1
# define FREE_NOP 0
# define COMPRESS_AFTER_X_FREE 32

#endif
