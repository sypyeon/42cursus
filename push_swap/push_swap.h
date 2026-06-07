/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sipyeon <sipyeon@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:02:45 by sipyeon           #+#    #+#             */
/*   Updated: 2025/01/21 21:34:54 by sipyeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_stack
{
	int		size;
	t_list	*head;
	t_list	*tail;
}	t_stack;

t_stack	*ft_init_stack(int *nums, int ac);
t_stack	*ft_newstack(void);
t_list	*ft_lstnew_nb(int nb);

void	ft_check_valid(char **av);
int		ps_int_dup_check(int *nums, int ac);

char	**ps_split(char **av);

int		*ft_arr_atoi(int ac, char **av);
int		*ft_minimize(int *nums, int *new_nums, int len);
int		*ft_arrange_nums(int ac, int *nums);

void	ft_sa(t_stack *a);
void	ft_sb(t_stack *b);
void	ft_ss(t_stack *a, t_stack *b);

void	ft_pa(t_stack *a, t_stack *b);
void	ft_pb(t_stack *a, t_stack *b);

void	ft_ra(t_stack *a);
void	ft_rb(t_stack *b);
void	ft_rr(t_stack *a, t_stack *b);

void	ft_rra(t_stack *a);
void	ft_rrb(t_stack *b);
void	ft_rrr(t_stack *a, t_stack *b);

int		ft_stack_align(t_stack *a, int ac);
void	ps_sort(t_stack *a, t_stack *b, int ac);

void	ps_free(void *to_free);
void	ps_av_free(char **to_free);
void	ps_free_stack(t_stack *stack);

#endif