/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:27:22 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:27:22 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function creates a string from all the characters of "str" 
///passed through the function "f".
/// @param str The string to operate on and copy
/// @param f The function that will iterate over each index/character 
///of the "str".
/// @return Returns the string with all its characters/indices operated on.
char	*ft_strmapi(char const *str, char (*f) (unsigned int, char))
{
	char			*aux_str;
	unsigned int	i;

	if (!str || !f)
		return (NULL);
	aux_str = malloc(ft_strlen(str) + 1);
	if (!aux_str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		aux_str[i] = f(i, str[i]);
		i ++;
	}
	aux_str[i] = '\0';
	return (aux_str);
}
