/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:27:48 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:27:48 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function searches for where to trim from the front.
/// @param str The string to trim.
/// @param set All the characters to consider.
/// @return Returns the index where the new string begins.
static int	ft_found_start(char const *str, char const *set)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] != '0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
				break ;
			j ++;
		}
		if (set[j] == '\0')
			break ;
		i ++;
	}
	return (i);
}

/// @brief This function searches for where to trim from the back.
/// @param str The string to trim.
/// @param set All the characters to consider.
/// @return Returns the index where the new string ends.
static int	ft_found_end(char const *str, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(str) - 1;
	j = 0;
	while (i >= 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
				break ;
			j ++;
		}
		if (set[j] == '\0')
			break ;
		i --;
	}
	return (i);
}

/// @brief This function trim all characters found in "set" from "str", 
///from both the front and the back, as long as the characters from 
///"set" are present.
/// @param str The string to trim.
/// @param set All the characters to consider.
/// @return The trimmed string.
char	*ft_strtrim(char const *str, char const *set)
{
	char	*aux_str;
	int		i;
	int		start;
	int		end;

	start = ft_found_start(str, set);
	end = ft_found_end(str, set);
	if (start <= end)
		aux_str = malloc(end - start + 2);
	else
		aux_str = malloc(1);
	if (!aux_str)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		aux_str[i] = str[start];
		start ++;
		i ++;
	}
	aux_str[i] = '\0';
	return (aux_str);
}
