/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:22:22 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/25 11:29:41 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ps_error(char *err_msg, t_stack **stack, char **split)
{
	write(2, err_msg, ft_strlen(err_msg));
	ft_free_matrix(split);
	ft_free(stack);
	exit(1);
	return (NULL);
}

t_stack	*ft_fill_multiple_av(int ac, char *av[])
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		if (ft_is_accept_for_atoi(av[i]) == 0)
			return (write(2, "Errore\n", 7), ft_free(&stack_a), NULL);
		nb = ft_strict_atoi(av[i]);
		if (nb == 0 && av[i][0] != '0')
			return (write(2, "Errore\n", 7), ft_free(&stack_a), NULL);
		if (i == 1)
			stack_a = ft_new_stack((int)nb);
		else
			ft_add_back(&stack_a, ft_new_stack((int)nb));
		i++;
	}
	if (ft_checkdup(stack_a) == 1)
		return (write(2, "Errore\n", 7), ft_free(&stack_a), NULL);
	return (stack_a);
}

t_stack	*ft_fill_two_av(char *av[])
{
	t_fill	f;

	f.stack_a = NULL;
	f.len = ft_strlen(av[1]);
	if (!av[1][0] || av[1][0] == ' ' || av[1][f.len - 1] == ' '
			|| ft_strnstr(av[1], "  ", f.len))
		return (write(2, "ERRORE\n", 7), NULL);
	f.splitted = ft_split(av[1], ' ');
	if (!f.splitted)
		return (write(2, "Errore\n", 7), NULL);
	f.i = -1;
	while (f.splitted[++f.i] != NULL)
	{
		f.nb = ft_strict_atoi(f.splitted[f.i]);
		if (f.nb == 0 && f.splitted[f.i][0] != '0')
			return (ps_error("Errore\n", &f.stack_a, f.splitted));
		if (f.i == 0)
			f.stack_a = ft_new_stack((int)f.nb);
		else
			ft_add_back(&f.stack_a, ft_new_stack((int)f.nb));
	}
	if (ft_checkdup(f.stack_a) == 1)
		return (ps_error("Errore\n", &f.stack_a, f.splitted));
	return (ft_free_matrix(f.splitted), f.stack_a);
}

//assegna l'indice da stack_len a 1 in ordine decrescente.
//il value piu' grande avra' index stack_len
void	ft_set_index(t_stack *stack_a, int stack_len)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		dish;

	while (--stack_len > 0)
	{
		ptr = stack_a;
		dish = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->dish == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->dish > dish && ptr->index == 0)
			{
				dish = ptr->dish;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_len;
	}
}

int	ft_checkdup(t_stack *a)
{
	t_stack	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->dish == tmp->dish)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
