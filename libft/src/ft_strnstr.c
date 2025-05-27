/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:27:33 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:27:33 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function searches for a string within another string with a
///limitation.
/// @param big The string to search in.
/// @param little The string to search for.
/// @param count The limit of characters to search.
/// @return Returns the string from where "little" has been found, 
///or NULL if it hasn't been found.
char	*ft_strnstr(const char *big, const char *little, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	aux;

	i = 0;
	j = 0;
	aux = 0;
	if (little[j] == '\0')
		return ((char *) big);
	while (big[i] != '\0' && i < count)
	{
		if (big[i] == little[j])
			j ++;
		else
		{
			j = 0;
			i = aux;
			aux ++;
		}
		i ++;
		if (little[j] == '\0')
			return ((char *) big + i - j);
	}
	return (NULL);
}
