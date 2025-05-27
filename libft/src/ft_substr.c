/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:27:54 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:27:54 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function trims a string by selecting the starting index and 
///the length.
/// @param str The string to trim.
/// @param start The starting index.
/// @param len The length of the string.
/// @return Returns the new trimmed string.
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*str2;
	size_t	len_str;
	int		i;

	if (!str)
		return (NULL);
	len_str = ft_strlen(str);
	if (start >= len_str)
		return (ft_strdup(""));
	if (len > len_str - start)
		len = len_str - start;
	str2 = malloc(sizeof(char) * (len + 1));
	if (str2 == NULL)
		return (NULL);
	i = 0;
	while ((size_t) i < len && str[i + start] != '\0')
	{
		str2[i] = str[start + i];
		i ++;
	}
	str2[i] = '\0';
	return (str2);
}
