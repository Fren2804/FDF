/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-26 14:17:39 by franmore          #+#    #+#             */
/*   Updated: 2025-02-26 14:17:39 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function converts a char/string number into an long, taking 
///into account "isspace" and only one sign. 
/// @param str The string number to convert.
/// @return The long number to return.
long	ft_atol(const char *str)
{
	long	i;
	int		minus;
	long	num;

	num = 0;
	minus = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i ++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -minus;
		i ++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - 48);
		i ++;
	}
	return (num * minus);
}
