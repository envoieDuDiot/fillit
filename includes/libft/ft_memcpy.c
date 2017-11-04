/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 18:55:11 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/03 12:47:44 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *ptrsrc;
	unsigned char *ptrdst;

	ptrsrc = (unsigned char *)src;
	ptrdst = (unsigned char *)dst;
	while (len--)
	{
		*ptrdst++ = *ptrsrc++;
	}
	return (dst);
}
