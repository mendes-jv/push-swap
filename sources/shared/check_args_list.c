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

#include "../../includes/push_swap.h"

static bool args_are_numbers(char **temp_args_list);
static bool	args_are_duplicates(char **args_list);
static bool	args_are_integers(char **args_list);

void	check_args_list(char **args_list, bool isSplit)
{
	if (!args_are_numbers(args_list) || args_are_duplicates(args_list)
		|| !args_are_integers(args_list))
	{
		free_args_list(args_list, isSplit);
		ft_handle_error(ERROR_MESSAGE);
	}
}

static bool	args_are_numbers(char **args_list)
{
	char *temp_arg;

	while (*args_list)
	{
		temp_arg = *args_list;
		if (*temp_arg == '-')
			temp_arg++;
		while (*temp_arg)
		{
			if (!ft_isdigit(*temp_arg))
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
	size_t	comp_len;
	while (*args_list)
	{
		index = 1;
		while (args_list[index])
		{
			comp_len = ft_operate((int) ft_strlen(*args_list),
								  (int) ft_strlen(args_list[index]), MAX);
			if (!ft_strncmp(*args_list, args_list[index], comp_len))
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

void	free_args_list(char **args_list, bool isSplit)
{
	if (isSplit)
	{
		ft_for_each((void **) args_list, free);
		free(args_list);
	}
}
