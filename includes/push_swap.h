/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jovicto2 <jovicto2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:18:02 by jovicto2          #+#    #+#             */
/*   Updated: 2023/12/07 11:18:04 by jovicto2         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Headers
# include "../libraries/libft/includes/libft.h"
# include <stdlib.h>

//Macros
# define ERROR_MESSAGE "Error\n"

//Structures
typedef struct s_stack
{
	int		value;
	t_stack	*prev;
	t_stack	*next;
}	t_stack;

//Prototypes
void	check_args(char **args_list);

#endif //PUSH_SWAP_H
