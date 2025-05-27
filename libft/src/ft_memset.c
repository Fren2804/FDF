/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:25:05 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:25:05 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function allows filling the desired number of bytes 
///in "dest" with unsigned integers.
/// @param dest The string/buffer that will be filled.
/// @param c The unsigned integer that we will use.
/// @param count The number of bytes to fill.
/// @return Returns the modified buffer/string.
void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	i;
	char	*aux;

	aux = (char *) dest;
	i = 0;
	while (i < count)
	{
		aux[i] = (unsigned char) c;
		i ++;
	}
	return (dest);
}
