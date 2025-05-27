/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:23:57 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:23:57 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function clears all the nodes and contents of the list.
/// @param lst The address of the list that needs to be cleared.
/// @param del The function responsible for freeing the content of each node.
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current_lst;
	t_list	*next_lst;

	if (!lst || !del)
		return ;
	current_lst = *lst;
	while (current_lst)
	{
		next_lst = current_lst->next;
		del(current_lst->content);
		free(current_lst);
		current_lst = next_lst;
	}
	*lst = NULL;
}
