/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rd-agost <rd-agost@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 22:01:28 by rd-agost          #+#    #+#             */
/*   Updated: 2024/06/20 16:03:24 by rd-agost         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strict_atoi(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (ft_is_accept_for_atoi(str) == 1)
	{
		nb = ft_atoi(str);
		if (nb == 0 && *str != '0')
			return (0);
		else
			return (nb);
	}
	return (0);
}

int	ft_is_accept_for_atoi(char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str);
	if (!str || !str[0])
		return (0);
	if (ft_plusminus(str[0]) && !ft_isdigit(str[1]))
		return (0);
	i = -1;
	if (ft_plusminus(str[0]))
		i = 0;
	while (str[++i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
	}
	return (1);
}
