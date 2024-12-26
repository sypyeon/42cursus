
#include"push_swap.h"
#include<stdio.h>

void	ft_print_stack(t_stack *a, t_stack *b)
{
	printf("------------------------------\n");
    t_list *a_stack;
    t_list *b_stack;
    int    d;

    a_stack = a->head;
    b_stack = b->head;
    d = 1;
    while (a->size - d + 1 > 0 || b->size - d + 1> 0)
    {
        if(a->size - d + 1 > 0 && b->size - d + 1 > 0)
            printf("%d = a :%d	b :%d\n",d, a_stack->nb, b_stack->nb);
        else if (b->size - d + 1 > 0)
            printf("%d = a :     b :%d\n",d, b_stack->nb);
        else if (a->size - d + 1 > 0)
            printf("%d = a :%d	b :\n",d, a_stack->nb);
        d++;
        if (a_stack)
            a_stack = a_stack->next;
        if (b_stack)
            b_stack = b_stack->next;
    }
    printf("------------------------------\n");
}

void	ft_check_sorting_functions(t_stack *a, t_stack *b)
{
	ft_print_stack(a,b);
	ft_pb(a, b);
	ft_print_stack(a,b);
	ft_pb(a, b);
	ft_print_stack(a,b);
	ft_sa(a);
	ft_print_stack(a,b);
	ft_sb(b);
	ft_print_stack(a,b);
	ft_ss(a, b);
	ft_print_stack(a,b);
	ft_ra(a);
	ft_print_stack(a,b);
	ft_rb(b);
	ft_print_stack(a,b);
	ft_rr(a, b);
	ft_print_stack(a, b);
	ft_rra(a);
	ft_print_stack(a, b);
	ft_rrb(b);
	ft_print_stack(a, b);
	ft_rrr(a, b);
	ft_print_stack(a, b);
	ft_pa(a, b);
	ft_print_stack(a, b);
	ft_pa(a, b);
	ft_print_stack(a, b);
}