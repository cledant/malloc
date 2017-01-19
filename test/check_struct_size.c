/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cledant <cledant@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 19:28:37 by cledant           #+#    #+#             */
/*   Updated: 2017/01/18 19:37:25 by cledant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

typedef struct		s_large
{
	struct s_large	*prev;
	struct s_large	*next;
	unsigned char	max_alloc;
	unsigned char	used_alloc;
	size_t			size[254];
	size_t			mem[254];
}					t_large;

int		main(void)
{
	printf("size of 'void *' : %lu\n", sizeof(void *));
	printf("size of 't_large' : %lu\n", sizeof(t_large));
	return (0);
}
