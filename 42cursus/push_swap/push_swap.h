/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:02:45 by sipyeon           #+#    #+#             */
/*   Updated: 2024/11/26 23:45:59 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct	s_list
{
	int				nb;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct	s_stack
{
	int		size;
	t_list	*head;
	t_list	*tail;
}	t_stack;


# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

#endif