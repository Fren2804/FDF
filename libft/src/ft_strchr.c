/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:25:57 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:25:57 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function searches for the first match with the desired 
///character and returns the string pointing to that position.
/// @param str The string/buffer where to search for the character.
/// @param c The character to search for.
/// @return Returns the string pointing to the position of the character, 
///the first position of the buffer if the character "c" is NULL 
///or NULL if it hasn't been found.
char	*ft_strchr(const char *str, int c)
{
	char			*aux_str;
	unsigned char	aux;

	aux_str = (char *) str;
	aux = (unsigned char) c;
	while (*aux_str != '\0')
	{
		if ((unsigned char) *aux_str == aux)
			return (aux_str);
		aux_str ++;
	}
	if (aux == '\0')
		return (aux_str);
	return (NULL);
}
