/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:39:12 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 20:07:32 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_STRUCT_H
# define MALLOC_STRUCT_H

typedef struct			s_tiny
{
	struct s_tint		*prev;
	struct s_tiny		*next;
	size_t				size;
	size_t				used;
	char				state[TINY_TAB];
	void				mem[TINY_TAB];
}						t_tiny;

typedef struct			s_small
{
	struct s_small		*prev;
	struct s_small		*next;
	size_t				size;
	size_t				used;
	char				state[SMALL_TAB];
	void				mem[SMALL_TAB];
}						t_small;

#endif
