/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:27:38 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:27:38 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function searches for the first match, beginning from the 
///back, with the desired character and returns the string pointing to that 
///position.
/// @param str The string/buffer where to search for the character.
/// @param c The character to search for.
/// @return Returns the string pointing to the position of the character
///or NULL if it hasn't been found.
char	*ft_strrchr(const char *str, int c)
{
	char	*aux_str;
	int		i;

	i = ft_strlen(str);
	aux_str = (char *) str;
	while (i >= 0)
	{
		if ((unsigned char) str[i] == (unsigned char) c)
			return (aux_str + i);
		i --;
	}
	return (NULL);
}
