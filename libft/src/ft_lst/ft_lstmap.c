/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntairatt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:04:22 by ntairatt          #+#    #+#             */
/*   Updated: 2023/02/22 23:02:12 by ntairatt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	new_lst = NULL;
	tmp_lst = NULL;
	if (lst == NULL || *f == NULL)
		return (0);
	while (lst != NULL)
	{
		tmp_lst = ft_lstnew(f(lst -> content));
		if (tmp_lst == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (0);
		}
		ft_lstadd_back(&new_lst, tmp_lst);
		lst = lst -> next;
	}
	return (new_lst);
}
