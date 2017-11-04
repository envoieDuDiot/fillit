/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 19:53:00 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/03 12:47:31 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int data, size_t len)
{
	unsigned char *tmp;

	tmp = dst;
	while (len--)
		*tmp++ = data;
	return (dst);
}
