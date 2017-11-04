/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:52:57 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/02 17:52:59 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int j;

	j = 0;
	while (src[j] != '\0' && j < len)
	{
		dst[j] = src[j];
		j++;
	}
	while (j < len)
	{
		dst[j] = '\0';
		j++;
	}
	return (dst);
}
