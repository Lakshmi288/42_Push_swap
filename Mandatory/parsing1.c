/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lps <lps@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:44:49 by lps               #+#    #+#             */
/*   Updated: 2023/12/02 16:33:18 by lps              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	process_quotes(const char *s, bool *in_quotes);
static int	process_digits(const char *s, bool in_quotes, bool *last_was_digit,
				int *count);

int	count_numbers(const char *s)
{
	int		count;
	bool	in_quotes;
	bool	last_was_digit;

	count = 0;
	in_quotes = false;
	last_was_digit = false;
	while (*s)
	{
		if (!process_quotes(s, &in_quotes))
		{
			process_digits(s, in_quotes, &last_was_digit, &count);
		}
		s++;
	}
	if (last_was_digit)
		count++;
	if (in_quotes)
		ft_error();
	return (count);
}

static int	process_quotes(const char *s, bool *in_quotes)
{
	if (*s == '\"')
	{
		*in_quotes = !(*in_quotes);
		return (1);
	}
	return (0);
}

static int	process_digits(const char *s, bool in_quotes, bool *last_was_digit,
		int *count)
{
	if (isspace((unsigned char)*s) && !in_quotes)
	{
		if (*last_was_digit)
			(*count)++;
		*last_was_digit = false;
	}
	else if (is_int((char *)s))
	{
		*last_was_digit = true;
	}
	else
	{
		ft_error();
	}
	return (0);
}

int	is_only_spaces(const char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

int	is_empty_or_whitespace(const char *str)
{
	while (*str)
	{
		if (!isspace((unsigned char)*str))
			return (0);
		str++;
	}
	return (1);
}
