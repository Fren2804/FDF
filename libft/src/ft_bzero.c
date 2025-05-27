/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:12:15 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:12:15 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
/// @brief This function puts the desired number of 0 in the desired area.
/// @param dest The area it points to.
/// @param count The number of 0 to place.
void	ft_bzero(void *dest, size_t count)
{
	size_t	i;
	char	*aux;

	aux = (char *) dest;
	i = 0;
	while (i < count)
	{
		aux[i] = 0;
		i ++;
	}
}
