/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:45:45 by lps               #+#    #+#             */
/*   Updated: 2023/12/02 16:33:38 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_sort(t_stack **stack)
{
	if (*stack && (*stack)->next != NULL)
	{
		if ((*stack)->data > (*stack)->next->data)
			sa(stack);
	}
}

void	three_sort(t_stack **stack_a)
{
	int	top;
	int	mid;
	int	bot;

	top = (**stack_a).data;
	mid = (**stack_a).next->data;
	bot = (**stack_a).next->next->data;
	if ((top > mid) && (bot > top))
		sa(stack_a);
	else if ((top > mid) && (mid > bot))
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if ((top > mid) && (mid < bot))
		ra(stack_a);
	else if ((top < mid) && (mid > bot) && (top < bot))
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if ((top < mid) && (mid > bot) && (top > bot))
		rra(stack_a);
}

void	five_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		stack_len_a;
	int		elements_to_move;

	stack_b = NULL;
	stack_len_a = stack_len(*stack_a);
	if (stack_len_a < 4 || stack_len_a > 6)
		return ;
	elements_to_move = stack_len_a - 3;
	while (elements_to_move > 0)
	{
		push_smallest_to_b(stack_a, &stack_b);
		elements_to_move--;
	}
	three_sort(stack_a);
	while (stack_b)
		pa(stack_a, &stack_b);
}

int	get_max_bits(t_stack *stack)
{
	int	max_value;
	int	bits;

	max_value = INT_MIN;
	bits = 0;
	while (stack)
	{
		if (stack->index > max_value)
			max_value = stack->index;
		stack = stack->next;
	}
	while (max_value)
	{
		max_value >>= 1;
		bits++;
	}
	return (bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	max_bits;
	int	len;

	i = -1;
	max_bits = get_max_bits(*stack_a);
	while (++i < max_bits)
	{
		len = stack_len(*stack_a);
		while (len-- > 0)
		{
			if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (*stack_b)
			pa(stack_a, stack_b);
	}
}
