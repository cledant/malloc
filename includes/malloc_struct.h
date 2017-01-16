/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 14:39:12 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 15:34:47 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_STRUCT_H
# define MALLOC_STRUCT_H

typedef struct			s_tiny
{
	struct s_tint		*prev;
	struct s_tiny		*next;
	char				state[TINY_STATE_TAB];
	void				mem[TINY_MEM_TAB];
}						t_tiny;

typedef struct			s_small
{
	struct s_small		*next;
	char				state[TINY_STATE_TAB];
	void				mem[TINY_MEM_TAB];
}						t_small;

#endif
