/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:52:01 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/02 18:53:47 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;
	int j;
	int begin;

	i = 0;
	j = 0;
	begin = 0;
	if (*little == '\0')
	{
		return ((char *)big);
	}
	while (big[i] != '\0')
	{
		begin = i;
		while (big[begin] == little[j])
		{
			j++;
			begin++;
			if (little[j] == '\0')
				return ((char *)&big[i]);
		}
		j = 0;
		i++;
	}
	return (0);
}
