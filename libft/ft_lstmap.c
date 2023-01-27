/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnicoter <lnicoter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 00:54:54 by lnicoter          #+#    #+#             */
/*   Updated: 2023/01/27 12:26:47 by lnicoter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**new_list;
	int		size;
	int		i;

	if (!lst)
		return (0);
	size = ft_lstsize(lst);
	i = 0;
	new_list = malloc(size * sizeof(t_list));
	while (i < size)
	{
		ft_lstadd_back(new_list, f(lst->content));
		del(lst->content);
		lst = lst->next;
		i++;
	}
	return (*new_list);
}
