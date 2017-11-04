/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 21:13:20 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/03 12:48:06 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	unsigned char *ptrstr;

	ptrstr = (unsigned char *)str;
	while (len--)
	{
		if (*ptrstr != (unsigned char)c)
			ptrstr++;
		else
			return (ptrstr);
	}
	return (NULL);
}
