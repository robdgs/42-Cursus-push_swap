/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_efficiency.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:58:46 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/25 10:57:08 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	costo x muovere ogni el stack B nella pos giusta in A
//	element in bottom half ? eff negativa : eff positiva

void	ft_is_efficient(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		len_a;
	int		len_b;

	temp_a = *stack_a;
	temp_b = *stack_b;
	len_a = ft_stack_len(temp_a);
	len_b = ft_stack_len(temp_b);
	while (temp_b)
	{
		temp_b->eff_b = temp_b->posiz;
		if (temp_b->posiz > len_b / 2)
			temp_b->eff_b = (len_b - temp_b->posiz) * -1;
		temp_b->eff_a = temp_b->target;
		if (temp_b->target > len_a / 2)
			temp_b->eff_a = (len_a - temp_b->target) * -1;
		temp_b = temp_b->next;
	}
}

void	ft_exec_most_eff(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		chpst;
	int		eff_a;
	int		eff_b;

	temp = *stack_b;
	chpst = INT_MAX;
	while (temp)
	{
		if (ft_absol(temp->eff_a) + ft_absol(temp->eff_b) < ft_absol(chpst))
		{
			chpst = ft_absol(temp->eff_b) + ft_absol(temp->eff_a);
			eff_a = temp->eff_a;
			eff_b = temp->eff_b;
		}
		temp = temp->next;
	}
	ft_exec_move(stack_a, stack_b, eff_a, eff_b);
}

//	Sceglie la migliore posiz di destinazione nello stack A per l'index
//	di un elemento nello stack B. Prima verifica se l'index dell'el B può
//	andare tra gli elementi nello stack A by controlling se c'è un el
//	nello stack A con un index maggiore. If not, trova l'el con
//	l'index più piccolo in A e assegna quello come posiz di dest.

static int	ft_target(t_stack **a, int b_idx,
								int target_idx, int target_pos)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index > b_idx && temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->posiz;
		}
		temp_a = temp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index < target_idx)
		{
			target_idx = temp_a->index;
			target_pos = temp_a->posiz;
		}
		temp_a = temp_a->next;
	}
	return (target_pos);
}

//	questa posiz mi serve per calcolare il costo per spostare l'el
//	correttamente nella sua target pos in stack A

void	ft_get_targ_pos(t_stack **a, t_stack **b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *b;
	ft_position(a);
	ft_position(b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = ft_target(a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target = target_pos;
		tmp_b = tmp_b->next;
	}
}
