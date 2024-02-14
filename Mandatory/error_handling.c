/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:42:10 by lps               #+#    #+#             */
/*   Updated: 2023/12/02 16:42:46 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_handler(t_error_data *error_data)
{
	if (error_data->arr)
		free(error_data->arr);
	if (error_data->tokens)
	{
		free_tokens(error_data->tokens);
	}
	ft_error();
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
