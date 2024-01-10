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

static bool	args_are_numbers(char **args_list);
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
	while (*args_list)
	{
		while (**args_list)
		{
			if (!ft_isdigit(**args_list))
				return (false);
			(*args_list)++;
		}
		args_list++;
	}
	return (true);
}

static bool	args_are_duplicates(char **args_list)
{
	char	**temp_args_list;

	while (*args_list)
	{
		temp_args_list = args_list;
		while (*temp_args_list)
		{
			if (!ft_strncmp(*args_list, *temp_args_list, ft_strlen(*args_list)))
				return (true);
			temp_args_list++;
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
