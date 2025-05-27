/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:25:00 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:25:00 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function copies the characters from "src" to "dest" with 
///a limit, and it allows for overlapping.
/// @param dest The parameter where the copy should be made.
/// @param src The parameter to copy.
/// @param count The parameter that limits the number of bytes to copy.
/// @return Returns the value of "dest" where the copy has been made.
void	*ft_memmove(void *dest, const void *src, size_t count)
{
	char	*aux_src;
	char	*aux_dest;
	size_t	i;

	i = 0;
	aux_src = (char *) src;
	aux_dest = (char *) dest;
	if (!dest && !src)
		return (NULL);
	if (aux_dest > aux_src)
	{
		while (count --)
			aux_dest[count] = aux_src[count];
	}
	else
	{
		while (i < count)
		{
			aux_dest[i] = aux_src[i];
			i ++;
		}
	}
	return (dest);
}
