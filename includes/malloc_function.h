/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:06:45 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 20:07:30 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_FUNCTION_H
# define MALLOC_FUNCTION_H

# include "malloc_struct.h"

void			malloc_init(char *init); //ok
inline int		malloc_getpagesize(void); //ok
t_tiny			*malloc_get_tiny(void); //ok
t_small			*malloc_get_small(void); //ok

#endif
