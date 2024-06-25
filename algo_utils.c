/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 14:55:18 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/24 17:28:40 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_absol(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_plusminus(char c)
{
	return (c == '-' || c == '+');
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	int					result;
	int					tmp;

	i = 0;
	sign = 1;
	result = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		tmp = result;
		result = result * 10 + str[i] - '0';
		if (result / 10 != tmp)
			return (0);
		i++;
	}
	return (result * sign);
}
