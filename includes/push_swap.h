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
# include <limits.h>

//Macros
# define ERROR_MESSAGE "Error\n"
# define A 0b1
# define B 0b10
# define AB 0b11

//Typedefs
typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;
typedef struct s_stack
{
	size_t	size;
	t_node	*top;
	t_node	*bottom;
}	t_stack;
typedef void	(*t_one_stack)(t_stack *a);
typedef void	(*t_double_stacks)(t_stack *a, t_stack *b);

//Prototypes
void	check_args_list(char **args_list);
void	sort_stack(t_stack *a, t_stack *b);
void	push(t_stack *a, t_stack *b);
void	swap(t_stack *a);
void	rotate(t_stack *a);
void	reverse_rotate(t_stack *a);
void	apply_move(t_stack *a, t_stack *b, char *move);


#endif //PUSH_SWAP_H
