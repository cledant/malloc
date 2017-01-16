/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:00:38 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 15:34:42 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <sys/mman.h>
# include "libft.h"
# include "malloc_function.h"
# include "malloc_struct.h"

# define PAGESIZE 4096
# define TINY_SIZE 16
# define TINY_STATE_TAB 256
# define TINY_MEM_TAB 239
# define SMALL_SIZE 32
# define SMALL_STATE_TAB 128
# define SMALL_MEM_TAB 123
# define LARGE_SIZE 256

#endif
