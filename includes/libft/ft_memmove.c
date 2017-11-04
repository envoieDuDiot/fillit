/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 20:34:29 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/03 17:32:57 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ptrdst;
	unsigned char *ptrsrc;

	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	if (ptrdst == ptrsrc)
		return (ptrdst);
	if (ptrdst > ptrsrc)
	{
		while (len--)
		{
			ptrdst[len] = ptrsrc[len];
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
