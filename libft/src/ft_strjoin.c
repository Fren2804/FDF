/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:26:59 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:26:59 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function joins two strings and returns the result.
/// @param str1 The first string to join.
/// @param str2 The second string to join.
/// @return Returns the union of the two strings.
char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*str;

	if (!str1 || !str2)
		return (NULL);
	str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (str1[i] != '\0')
	{
		str[i] = str1[i];
		i ++;
	}
	j = i;
	i = 0;
	while (str2[i] != '\0')
	{
		str[j + i] = str2[i];
		i ++;
	}
	str[j + i] = '\0';
	return (str);
}
