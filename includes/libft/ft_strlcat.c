/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 12:01:04 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/09 12:39:32 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			slen;

	i = 0;
	j = 0;
	slen = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (size > 0)
		while (src[j] && i < size - 1)
			dst[i++] = src[j++];
	if (j > 0)
	{
		dst[i] = 0;
		return (slen + i - j);
	}
	return (slen + i);
}
