/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:15:33 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/24 16:25:50 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
	{
		if (stack->dish > stack->next->dish)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	ft_push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !ft_is_sorted(*stack_a))
		ft_sa(stack_a);
	else if (stack_size == 3)
		ft_easy_sort(stack_a);
	else if (stack_size > 3 && !ft_is_sorted(*stack_a))
		ft_terror_sort(stack_a, stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	stack_b = NULL;
	if (argc == 2)
		stack_a = ft_fill_two_av(argv);
	if (argc > 2)
		stack_a = ft_fill_multiple_av(argc, argv);
	stack_size = ft_stack_len(stack_a);
	ft_set_index(stack_a, stack_size + 1);
	ft_push_swap(&stack_a, &stack_b, stack_size);
	ft_free(&stack_a);
	ft_free(&stack_b);
	return (0);
}
