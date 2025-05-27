/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:08:38 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:08:38 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
/// @brief This function converts a char/string number into an integer, taking 
///into account "isspace" and only one sign. 
/// @param str The string number to convert.
/// @return The integer number to return.
int	ft_atoi(const char *str)
{
	int	i;
	int	minus;
	int	num;

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
