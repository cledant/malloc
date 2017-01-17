/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:39:12 by cledant           #+#    #+#             */
/*   Updated: 2017/01/17 19:08:01 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_STRUCT_H
# define MALLOC_STRUCT_H

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
	void				*mem;
}						t_large;

typedef enum			e_type
{
	TINY, SMALL, LARGE
}						t_type;

#endif
