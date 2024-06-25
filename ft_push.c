/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 23:17:09 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/24 16:16:16 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_push(t_stack **src, t_stack **dest)
{
	t_stack		*temp;

	if (*src == NULL)
		return ;
	if (*dest == NULL)
	{
		temp = (*src)->next;
		(*src)->next = NULL;
		*dest = *src;
		*src = temp;
		return ;
	}
	temp = (*src)->next;
	(*src)->next = (*dest);
	*dest = *src;
	*src = temp;
}

void	ft_pa(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
