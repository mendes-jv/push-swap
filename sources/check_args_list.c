/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:00:40 by jovicto2          #+#    #+#             */
/*   Updated: 2023/12/11 11:00:41 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool args_are_numbers(char **temp_args_list);
static bool	args_are_duplicates(char **args_list);
static bool	args_are_integers(char **args_list);

void	check_args_list(char **args_list)
{
	if (!args_are_numbers(args_list) || args_are_duplicates(args_list)
		|| !args_are_integers(args_list))
		ft_handle_error(ERROR_MESSAGE);
}

static bool	args_are_numbers(char **args_list)
{
	char *temp_arg;

	while (*args_list)
	{
		temp_arg = *args_list;
		while (*temp_arg)
		{
			if (!ft_isdigit(*temp_arg))//TODO: Change to handle negative numbers
				return (false);
			temp_arg++;
		}
		args_list++;
	}
	return (true);
}

static bool	args_are_duplicates(char **args_list)
{
	size_t	index;

	while (*args_list)
	{
		index = 0;
		while (args_list[index + 1])
		{
			if (!ft_strncmp(args_list[index], args_list[index + 1], ft_strlen(*args_list)))
				return (true);
			index++;
		}
		args_list++;
	}
	return (false);
}

static bool	args_are_integers(char **args_list)
{
	while (*args_list)
	{
		if (ft_atol(*args_list) > INT_MAX || ft_atol(*args_list) < INT_MIN)
			return (false);
		args_list++;
	}
	return (true);
}
