/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:32:57 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/25 10:56:35 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	Reverse rotates both stack A and B until one of them is in position.
//	The given cost is negative since both positions are in the bottom half
//	of their respective stacks
void	ft_exec_rrr(t_stack **a, t_stack **b, int *eff_a, int *eff_b)
{
	while (*eff_a < 0 && *eff_b < 0)
	{
		(*eff_a)++;
		(*eff_b)++;
		ft_rrr(a, b);
	}
}

//The cost is decreased as the stacks are
//rotated, when one reaches 0, the stack has been rotated as far as possible
//and the top position is correct.
void	ft_exec_rr(t_stack **a, t_stack **b, int *eff_a, int *eff_b)
{
	while (*eff_a > 0 && *eff_b > 0)
	{
		(*eff_a)--;
		(*eff_b)--;
		ft_rr(a, b);
	}
}

//costo negativo ? reverse rotate : rotate (finche' stack a non e' ordinato)
void	ft_exec_rotation_a(t_stack **a, int *eff)
{
	while (*eff)
	{
		if (*eff > 0)
		{
			ft_ra(a);
			(*eff)--;
		}
		else if (*eff < 0)
		{
			ft_rra(a);
			(*eff)++;
		}
	}
}

//costo negativo ? reverse rotate : rotate (finche' stack b non e' ordinato)
void	ft_exec_rotation_b(t_stack **b, int *eff)
{
	while (*eff)
	{
		if (*eff > 0)
		{
			ft_rb(b);
			(*eff)--;
		}
		else if (*eff < 0)
		{
			ft_rrb(b);
			(*eff)++;
		}
	}
}

void	ft_exec_move(t_stack **a, t_stack **b, int eff_a, int eff_b)
{
	if (eff_a < 0 && eff_b < 0)
		ft_exec_rrr(a, b, &eff_a, &eff_b);
	else if (eff_a > 0 && eff_b > 0)
		ft_exec_rr(a, b, &eff_a, &eff_b);
	ft_exec_rotation_a(a, &eff_a);
	ft_exec_rotation_b(b, &eff_b);
	ft_pa(b, a);
}
