/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:52:48 by lps               #+#    #+#             */
/*   Updated: 2023/12/02 16:33:24 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ra():
*   1. Checks if there's enough elements to rotate.
*   2. Find the last element in the list.
*   3. Assign the correct values to First, Second and Last.
*/
t_stack	*rotate(t_stack *stack)
{
	t_stack	*first;
	t_stack	*second;
	t_stack	*last;

	if (stack == NULL || stack->next == NULL)
		return (stack);
	first = stack;
	second = stack->next;
	last = stack;
	while (last->next != NULL)
		last = last->next;
	first->next = NULL;
	first->prev = last;
	last->next = first;
	second->prev = NULL;
	return (second);
}

void	ra(t_stack **stack_a)
{
	*stack_a = rotate(*stack_a);
	ft_putstr("ra\n");
}

void	rb(t_stack **stack_b)
{
	*stack_b = rotate(*stack_b);
	ft_putstr("rb\n");
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = rotate(*stack_a);
	*stack_b = rotate(*stack_b);
	ft_putstr("rr\n");
}
