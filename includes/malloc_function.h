/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_function.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:06:45 by cledant           #+#    #+#             */
/*   Updated: 2017/01/16 15:34:44 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_FUNCTION_H
# define MALLOC_FUNCTION_H

void			malloc_init(char *init);
inline int		malloc_getpagesize(void); //ok
int				malloc_init_tiny(void);
int				malloc_init_small(void);

#endif
