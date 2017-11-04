/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 14:38:33 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/08 20:46:59 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	last;
	size_t	first;
	char	*str;

	i = 0;
	str = (char *)s;
	if (!s)
		return (NULL);
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '\0')
		return (ft_strdup(""));
	first = i;
	i = 0;
	while (str[i])
		i++;
	while (i > 0 && (ft_isspace(str[i]) || str[i] == '\0'))
		i--;
	last = i;
	return (ft_strsub(s, first, last - first + 1));
}
