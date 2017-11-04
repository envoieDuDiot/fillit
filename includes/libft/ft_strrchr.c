/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 14:27:54 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/03 16:04:57 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *ptrstr;
	char *lastptr;

	ptrstr = (char *)str;
	if (*str == c)
		lastptr = (char *)str;
	else
		lastptr = 0;
	while (*ptrstr)
	{
		if (*ptrstr == c)
			lastptr = ptrstr;
		ptrstr++;
	}
	if (*ptrstr == c)
		lastptr = ptrstr;
	return (lastptr);
}
