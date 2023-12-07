/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:18:11 by jovicto2          #+#    #+#             */
/*   Updated: 2023/12/07 11:18:13 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
    if (!argv || argc < 2 || args_are_numbers() || !args_are_duplicates() || !args_are_integers())
		handle_error(ERROR_MESSAGE);
	//TODO: args_are_valid() and check if any string is empty
	//TODO: if argv == 2 -> split()
	//TODO: atoi()
	if (args_are_sorted())
		exit(EXIT_SUCCESS);
	//TODO: conditional structure to choose the best algorithm for args number
    return (EXIT_SUCCESS);
}