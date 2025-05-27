/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:27:10 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:27:10 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function safely copies a string up to the desired length.
/// @param dest The destination string where the copy will be made.
/// @param src The string that will be copied.
/// @param count The desired length of the copy.
/// @return Returns the length of "src".
size_t	ft_strlcpy(char *dest, const char *src, size_t count)
{
	size_t	i;

	i = 0;
	if (count == 0)
		return (ft_strlen(src));
	while (i < count - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
