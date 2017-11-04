/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achaussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 15:52:28 by achaussa          #+#    #+#             */
/*   Updated: 2017/05/18 16:02:14 by achaussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*ret_last;

	if (!lst || !f)
		return ((t_list *)NULL);
	ret_last = f(lst);
	ret = ret_last;
	if (ret == NULL)
		return ((t_list *)NULL);
	while (lst->next)
	{
		lst = lst->next;
		if (!(ret_last->next = f(lst)))
			return (NULL);
		ret_last = ret_last->next;
	}
	return (ret);
}
