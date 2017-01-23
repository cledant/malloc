/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:06:45 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 20:09:43 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_FUNCTION_H
# define MALLOC_FUNCTION_H

# include "malloc_struct.h"

int					malloc_init(char *init);
int					malloc_getpagesize(void);
t_tiny				*malloc_get_tiny(void);
t_tiny				*malloc_new_tiny(void);
t_small				*malloc_get_small(void);
t_small				*malloc_new_small(void);
t_large				*malloc_get_large(void);
t_large				*malloc_new_large(void);
void				*malloc_tiny(const size_t size);
size_t				malloc_get_number_alloc(const size_t size,
						const size_t size_alloc, const t_type type);
short int			malloc_get_userid(const char *index, const t_type type);
short int			malloc_get_allocid(const short int *state,
						const size_t nb_alloc, const t_type type);
t_tiny				*malloc_get_available_tiny(const size_t size,
						short int *alloc_id);
int					malloc_add_new_tiny(t_tiny *header);
void				*malloc_allocate_tiny(t_tiny *header, const size_t nb_alloc,
						const short int user_id, const short int alloc_id);
void				*malloc_small(const size_t size);
t_small				*malloc_get_available_small(const size_t nb_tiny,
						short int *alloc_id);
int					malloc_add_new_small(t_small *header);
void				*malloc_allocate_small(t_small *header,
						const size_t nb_alloc, const short int user_id,
						const short int alloc_id);
void				*malloc_large(const size_t size);
int					malloc_add_new_large(t_large *large);
t_large				*malloc_get_available_large(void);
void				*malloc_allocate_large(t_large *header,
						const size_t nb_alloc);

#endif
