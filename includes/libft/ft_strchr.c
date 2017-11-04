/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 13:59:00 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/03 14:27:14 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	*ptrstr;

	i = 0;
	ptrstr = (char *)str;
	if (ptrstr[i] == (char)c)
		return (&ptrstr[i]);
	while (ptrstr[i++])
	{
		if (ptrstr[i] == (char)c)
			return (&ptrstr[i]);
	}
	return (NULL);
}
