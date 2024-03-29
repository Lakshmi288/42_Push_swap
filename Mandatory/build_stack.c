/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:41:37 by lps               #+#    #+#             */
/*   Updated: 2023/12/02 16:41:19 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	append_node(int data, t_stack **prevNode)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	(*prevNode)->next = new_node;
	new_node->prev = *prevNode;
	new_node->next = NULL;
	new_node->data = data;
}

t_stack	*create_stack(int argc, int *arr)
{
	int		i;
	t_stack	*head;
	t_stack	*node;

	head = NULL;
	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = arr[0];
	node->prev = NULL;
	node->next = NULL;
	head = node;
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			append_node(arr[i], &node);
			node = node->next;
			i++;
		}
	}
	return (head);
}

t_stack	*get_next_min_value(t_stack *stack, long last_min_value)
{
	long	min_value;
	t_stack	*smallest_next_node;

	min_value = 2147483649;
	smallest_next_node = NULL;
	while (stack)
	{
		if (stack->data < min_value && stack->data > last_min_value)
		{
			min_value = stack->data;
			smallest_next_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_next_node);
}

void	assign_indexes(t_stack **stack)
{
	int		len;
	int		index;
	t_stack	*node;
	long	last_min_value;

	len = stack_len(*stack);
	index = 0;
	node = NULL;
	last_min_value = -2147483649;
	while (len-- > 0)
	{
		node = get_next_min_value(*stack, last_min_value);
		last_min_value = node->data;
		node->index = index;
		index++;
	}
}
