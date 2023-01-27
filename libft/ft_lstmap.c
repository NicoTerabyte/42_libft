/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:54:54 by lnicoter          #+#    #+#             */
/*   Updated: 2023/01/27 01:37:05 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// incompleto
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	current = new_list;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew(f(lst->content));
		current = current->next;
		del(lst->content);
		lst = lst->next;
	}
	current->next = NULL;
	return (new_list);
}
