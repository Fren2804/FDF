/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:24:31 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:24:31 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function gets the number of nodes in a list.
/// @param lst The list from which we want to know the size.
/// @return Returns the size of the list or the number of nodes.
int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*temp;

	temp = lst;
	i = 0;
	while (temp)
	{
		temp = temp->next;
		i ++;
	}
	return (i);
}
