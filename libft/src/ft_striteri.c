/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:26:38 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:26:38 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function performs an operation on each character/index
/// of the string.
/// @param str The string where the operations will be performed.
/// @param f The function that will iterate over each index/character 
///of the "str".
void	ft_striteri(char *str, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!str || !f)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		f(i, &str[i]);
		i ++;
	}
}
