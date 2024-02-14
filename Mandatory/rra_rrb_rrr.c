/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:53:12 by lps               #+#    #+#             */
/*   Updated: 2023/12/02 16:33:28 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*rev_rotate(t_stack *stack)
{
	t_stack	*first;
	t_stack	*last;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	first = stack;
	last = stack;
	while (last->next != NULL)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	return (last);
}

void	rra(t_stack **stack_a)
{
	*stack_a = rev_rotate(*stack_a);
	ft_putstr("rra\n");
}

void	rrb(t_stack **stack_b)
{
	*stack_b = rev_rotate(*stack_b);
	ft_putstr("rrb\n");
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = rev_rotate(*stack_a);
	*stack_b = rev_rotate(*stack_b);
	ft_putstr("rrr\n");
}
