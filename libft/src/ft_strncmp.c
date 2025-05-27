/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:27:29 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:27:29 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function compares two strings and returns the difference 
///between the character of "str1" and the character of "str2", and compares 
///up to the desired length.
/// @param str1 First string to compare.
/// @param str2 Second string to compare.
/// @param count Limits of characters to compare.
/// @return Returns the difference between the characters of 
///the two strings, or zero if there is no difference.
int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	size_t	i;

	i = 0;
	while (str1[i] != '\0' && str2[i] != '\0' && i < count)
	{
		if (str1[i] != str2[i])
			return ((unsigned char) str1[i] - (unsigned char) str2[i]);
		i ++;
	}
	if (i < count)
	{
		return ((unsigned char) str1[i] - (unsigned char) str2[i]);
	}
	return (0);
}
