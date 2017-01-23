/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem_function.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 08:57:16 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 10:47:11 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHOW_ALLOC_MEM_FUNCTION_H
# define SHOW_ALLOC_MEM_FUNCTION_H

# include "malloc_struct.h"

void			show_alloc_mem(void);
void			sam_itoa_base_stack(size_t num, const char *base);
t_list_alloc	*sam_get_list(void);
t_list_alloc	*sam_get_last_list(void);
t_list_alloc	*sam_new_list(void);
int				sam_add_new_list(t_list_alloc *list);
int				sam_reset_list(void);
int				sam_get_tiny_list(void);
int				sam_get_small_list(void);
int				sam_get_large_list(void);
int				sam_display_list(void);
size_t			sam_get_max_print(void);
size_t			sam_get_zone_to_display(char *type, size_t *size);
size_t			sam_set_displayed(const size_t ptr);
void			sam_display_zone(const size_t ptr, const char type,
					size_t *mem, const size_t zone_size);
void			sam_clean_memory(void);
void			sam_display_zone_header(const char type, const size_t addr);
void			sam_display_zone_alloc(const size_t addr, const size_t size);
void			sam_display_total_mem(const size_t size);
void			sam_display_zone_large(const size_t addr, size_t *mem,
					const size_t size);
void			sam_display_zone_tiny(const size_t addr, size_t *mem);
void			sam_display_zone_small(const size_t addr, size_t *mem);

#endif
