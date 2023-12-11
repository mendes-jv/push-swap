/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:00:40 by jovicto2          #+#    #+#             */
/*   Updated: 2023/12/11 11:00:41 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

_Bool	args_are_numbers(char **args_list);
_Bool	args_are_duplicates(char **args_list);
_Bool	args_are_integers(char **args_list);

void	check_args(char **args_list)
{
	if (!args_are_numbers(args_list) || args_are_duplicates(args_list)
		|| !args_are_integers(args_list))
		handle_error(ERROR_MESSAGE);
}

_Bool	args_are_numbers(char **args_list)
{
	while (*args_list)
	{
		while (**args_list)
		{
			if (!ft_isdigit(**args_list))
				return (0);
			(*args_list)++;
		}
		args_list++;
	}
	return (1);
}

_Bool	args_are_duplicates(char **args_list)
{
	char	**temp_args_list;

	while (*args_list)
	{
		temp_args_list = args_list;
		while (*temp_args_list)
		{
			if (ft_strcmp(*args_list, *temp_args_list) == 0)
				return (1);
			temp_args_list++;
		}
		args_list++;
	}
	return (0);
}

_Bool	args_are_integers(char **args_list)
{
	while (*args_list)
	{
		if (ft_atoi(*args_list) > INT_MAX || ft_atoi(*args_list) < INT_MIN)
			return (0);
		args_list++;
	}
	return (1);
}
