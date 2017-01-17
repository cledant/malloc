/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:06:45 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 17:02:24 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_FUNCTION_H
# define MALLOC_FUNCTION_H

# include "malloc_struct.h"

void				malloc_init(char *init); //ok
inline int			malloc_getpagesize(void); //ok
t_tiny				*malloc_get_tiny(void); //ok
t_tiny				*malloc_new_tiny(void); //ok
t_small				*malloc_get_small(void); //ok
t_small				*malloc_new_small(void); //ok
t_large				*malloc_get_large(void); //ok
t_large				*malloc_new_large(void); //ok
int					malloc_prealloc_large(t_large **header); //ok
int					malloc_clean_prealloc_large(t_large **header); //ok
void				*malloc_tiny(const size_t size);
inline size_t		malloc_get_number_alloc(const size_t size,
						const size_t size_alloc, const t_type type);
unsigned short int	malloc_get_userid(const char *index, const t_type type);
unsigned short int	malloc_get_allocid(const unsigned short int *state,
						const size_t nb_alloc, const t_type type);
t_tiny				*malloc_get_available_tiny(void);
int					malloc_add_new_tiny(t_tiny *header);

#endif
