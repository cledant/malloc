/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc_function.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 10:07:52 by cledant           #+#    #+#             */
/*   Updated: 2017/01/24 17:37:26 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALLOC_FUNCTION_H
# define REALLOC_FUNCTION_H

# include "malloc_struct.h"

int		realloc_seek_header_and_type(void **header, t_type *type,
			const void *ptr);
t_large	*realloc_seek_header_for_addr_large(const size_t addr);
void	*realloc_tiny(t_tiny *header, void *ptr, const size_t new_size);
void	*realloc_new_ptr(void *ptr, const size_t new_size,
			const size_t old_size);
void	realloc_change_size_tiny(t_tiny *header, const short int alloc_id,
			const size_t cur_nb_alloc, const size_t new_nb_alloc);
void	*realloc_small(t_small *header, void *ptr,
			const size_t new_size);
void	realloc_change_size_small(t_small *header, const short int alloc_id,
			const size_t cur_nb_alloc, const size_t new_nb_alloc);
void	*realloc_large(t_large *header, void *ptr,
			const size_t new_size);
void	*reallocf_wrapper(void *old_ptr, void *new_ptr);
void	*realloc_special_case(void *ptr);

#endif
