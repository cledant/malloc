/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:39:12 by cledant           #+#    #+#             */
/*   Updated: 2017/01/23 20:46:12 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_STRUCT_H
# define MALLOC_STRUCT_H

# define TINY_TAB 1024
# define SMALL_TAB 4096
# define LARGE_TAB 254
# define ALLOC_TAB 226

typedef struct			s_tiny
{
	struct s_tiny		*prev;
	struct s_tiny		*next;
	int					max_alloc;
	int					used_alloc;
	short int			state[TINY_TAB];
	char				index[TINY_TAB];
	void				*mem;
}						t_tiny;

typedef struct			s_small
{
	struct s_small		*prev;
	struct s_small		*next;
	int					max_alloc;
	int					used_alloc;
	short int			state[SMALL_TAB];
	char				index[SMALL_TAB];
	void				*mem;
}						t_small;

typedef struct			s_large
{
	struct s_large		*prev;
	struct s_large		*next;
	unsigned char		max_alloc;
	unsigned char		used_alloc;
	size_t				size[LARGE_TAB];
	size_t				mem[LARGE_TAB];
}						t_large;

typedef enum			e_type
{
	TINY, SMALL, LARGE
}						t_type;

typedef struct			s_allocid
{
	size_t				i;
	short int			id_ok;
	size_t				free;
	size_t				max;
}						t_allocid;

typedef struct			s_list_alloc
{
	struct s_list_alloc	*prev;
	struct s_list_alloc	*next;
	unsigned char		max;
	unsigned char		used;
	size_t				size[ALLOC_TAB];
	size_t				ptr[ALLOC_TAB];
	char				disp[ALLOC_TAB];
	char				type[ALLOC_TAB];
}						t_list_alloc;

typedef struct			s_display_info
{
	size_t				size;
	size_t				ptr;
	char				type;
}						t_display_info;

typedef struct			s_display_zone_tiny_small
{
	size_t				i;
	size_t				addr;
	size_t				n_alloc;
}						t_display_zone_tiny_small;

#endif
