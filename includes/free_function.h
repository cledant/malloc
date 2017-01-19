/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_function.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 10:48:27 by cledant           #+#    #+#             */
/*   Updated: 2017/01/19 15:48:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_FUNCTION_H
# define FREE_FUNCTION_H

# include "malloc_struct.h"

int		free_tiny(const size_t addr); //ok
t_tiny	*free_seek_header_for_addr_tiny(const size_t addr);
int		free_is_valid_alloc_tiny(const t_tiny *header, const size_t addr,
			short int *user_id, short int *alloc_id); //ok
int		free_seek_nb_alloc_tiny(const t_tiny *header, const short int user_id,
			const short int alloc_id, size_t *nb_alloc);
int		free_deallocate_tiny(t_tiny *header, const short int user_id,
			const short int alloc_id, const size_t nb_alloc);
void	free_check_to_delete_header_tiny(t_tiny *header);

#endif
