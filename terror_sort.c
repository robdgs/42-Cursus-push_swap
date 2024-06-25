/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terror_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:22:15 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/25 11:02:06 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_keep_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = ft_stack_len(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			ft_pb(stack_a, stack_b);
			pushed++;
		}
		else
			ft_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		ft_pb(stack_a, stack_b);
		pushed++;
	}
}

//	Dopo che the most of lo stack e' ordinato, shift stack_a until lowest val
//	non è in cima. Se si trova nella metà inferiore dello stack, esegui
//	rev rotate altrimenti rotate finché non è in cima allo stack.

static void	ft_shift(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = ft_stack_len(*stack_a);
	lowest_pos = ft_lowst_index_pos(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			ft_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ft_ra(stack_a);
			lowest_pos--;
		}
	}
}

void	ft_terror_sort(t_stack **stack_a, t_stack **stack_b)
{
	ft_keep_three(stack_a, stack_b);
	ft_easy_sort(stack_a);
	while (*stack_b)
	{
		ft_get_targ_pos(stack_a, stack_b);
		ft_is_efficient(stack_a, stack_b);
		ft_exec_most_eff(stack_a, stack_b);
	}
	if (!ft_is_sorted(*stack_a))
		ft_shift(stack_a);
}
