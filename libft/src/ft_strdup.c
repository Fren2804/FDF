/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:26:30 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:26:30 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function makes an exact copy of the desired string and 
///returns it, without needing a "dst".
/// @param src The string to copy.
/// @return Returns the copy of the string "str".
char	*ft_strdup(const char *str)
{
	char	*aux_str;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	aux_str = malloc (sizeof(char) * (len + 1));
	if (!aux_str)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		aux_str[i] = str[i];
		i ++;
	}
	aux_str[i] = '\0';
	return (aux_str);
}
