/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:24:53 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:24:53 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
/// @brief This function copies the content of "src" into "dest" up to a limit.
/// @param dest The parameter where the copy should be made.
/// @param src The parameter to copy.
/// @param count The parameter that limits the number of bytes to copy.
/// @return Returns the value of "dest" where the copy has been made.
void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;
	char	*aux_dest;
	char	*aux_src;

	if (!dest && !src)
		return (NULL);
	aux_dest = (char *) dest;
	aux_src = (char *) src;
	i = 0;
	while (i < count)
	{
		aux_dest[i] = aux_src[i];
		i ++;
	}
	return (dest);
}
