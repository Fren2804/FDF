/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:26:52 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:26:52 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function safely concatenates two strings up to a desired size.
/// @param dest The string where the concatenation will be performed and the 
///first part of it.
/// @param src The string that will be concatenated with "dest".
/// @param count The desired size of the concatenation.
/// @return Return the total length of the string they tried to create.
size_t	ft_strlcat(char *dest, const char *src, size_t count)
{
	size_t	len_dest;
	size_t	i;
	char	*aux_src;

	len_dest = ft_strlen(dest);
	aux_src = (char *) src;
	if (count <= len_dest)
		return (count + ft_strlen(aux_src));
	i = 0;
	while (aux_src[i] != '\0' && i < count - len_dest - 1)
	{
		dest[len_dest + i] = aux_src[i];
		i ++;
	}
	dest[len_dest + i] = '\0';
	return (len_dest + ft_strlen(aux_src));
}
