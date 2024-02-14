/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toolbox3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:48:36 by lps               #+#    #+#             */
/*   Updated: 2023/12/02 16:34:02 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	is_stack_sorted(t_stack **stack)
{
	t_stack	*current;

	current = *stack;
	while (current->next != NULL)
	{
		if (current->data > current->next->data)
			return ;
		current = current->next;
	}
	free_stack(stack);
	exit(12);
}
