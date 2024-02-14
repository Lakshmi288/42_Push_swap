/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:52:27 by lps               #+#    #+#             */
/*   Updated: 2023/12/02 16:33:01 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*first_a;

	if (*stack_a == NULL)
		return ;
	first_a = *stack_a;
	*stack_a = (*first_a).next;
	if (*stack_a != NULL)
		(*stack_a)->prev = NULL;
	first_a->next = *stack_b;
	if (*stack_b != NULL)
		(*stack_b)->prev = first_a;
	*stack_b = first_a;
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}
