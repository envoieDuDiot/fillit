/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 12:22:12 by achaussa          #+#    #+#             */
/*   Updated: 2017/06/08 15:23:52 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_atoi(const char *str)
{
	size_t	i;
	size_t	temp;
	int		sign;

	i = 0;
	temp = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (ft_isdigit(str[i + 1]))
			sign = (str[i] == '+') ? 1 : -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		temp = (temp * 10) + (str[i] - '0');
		i++;
	}
	return (temp * sign);
}
