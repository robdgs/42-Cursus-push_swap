/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easy_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 23:06:14 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/20 17:39:38 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_highest_val(t_stack *stack)
{
	int				highest;
	t_stack			*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->dish > highest)
		{
			highest = stack->dish;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

void	ft_easy_sort(t_stack **stack_a)
{
	t_stack	*highest;

	highest = ft_highest_val(*stack_a);
	if (*stack_a == highest)
		ft_ra(stack_a);
	else if ((*stack_a)->next == highest)
		ft_rra(stack_a);
	if ((*stack_a)->dish > (*stack_a)->next->dish)
		ft_sa(stack_a);
}
