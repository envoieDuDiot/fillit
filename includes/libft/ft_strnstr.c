/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:10:19 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/07 17:08:27 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(little);
	if (!little[0])
		return ((char *)big);
	while (big[i] && n-- >= len)
	{
		if (ft_strncmp(little, &big[i], len) == 0)
			return ((char *)(&big[i]));
		i++;
	}
	return (NULL);
}
