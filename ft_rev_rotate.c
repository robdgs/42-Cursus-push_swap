/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 15:55:14 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/24 16:16:21 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//The last element becomes the first one

static void	ft_rev_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*penultimate;
	t_stack	*last;

	last = ft_stack_last(*stack);
	penultimate = ft_stack_penultimate(*stack);
	temp = *stack;
	*stack = last;
	(*stack)->next = temp;
	penultimate->next = NULL;
}

void	ft_rra(t_stack **stack_a)
{
	ft_rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b)
{
	ft_rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rev_rotate(stack_a);
	ft_rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
