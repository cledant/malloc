/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:06:45 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 14:00:00 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_FUNCTION_H
# define MALLOC_FUNCTION_H

# include "malloc_struct.h"

void			malloc_init(char *init); //ok
inline int		malloc_getpagesize(void); //ok
t_tiny			*malloc_get_tiny(void); //ok
t_tiny			*malloc_new_tiny(void); //ok
t_small			*malloc_get_small(void); //ok
t_small			*malloc_new_small(void); //ok
t_large			*malloc_get_large(void); //ok
t_large			*malloc_new_large(void); //ok
int				malloc_prealloc_large(t_large **header); //ok
int				malloc_clean_prealloc_large(t_large **header); //ok

#endif
