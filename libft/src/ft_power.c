/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-28 14:41:31 by franmore          #+#    #+#             */
/*   Updated: 2025-03-28 14:41:31 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief 
/// @param base 
/// @param exp 
/// @return 
int	ft_power(int base, int exp)
{
	int	i;
	int	result;

	i = 0;
	result = 1;
	if (exp < 0)
		return (0);
	while (i < exp)
	{
		result *= base;
		i ++;
	}
	return (result);
}
