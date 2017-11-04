/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 00:11:13 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/09 12:38:17 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int				sign;
	char			*str;
	unsigned int	nbr;
	unsigned int	len;

	sign = (n >= 0) ? 1 : -1;
	nbr = n * sign;
	len = (sign == -1) ? 2 : 1;
	while (nbr /= 10)
		len++;
	if (!(str = (char*)malloc((sizeof(char) * len) + 1)))
		return (NULL);
	str[len] = '\0';
	nbr = n * sign;
	while (len--)
	{
		str[len] = nbr % 10 + '0';
		nbr /= 10;
	}
	str[0] = (sign == -1) ? '-' : str[0];
	return (str);
}
