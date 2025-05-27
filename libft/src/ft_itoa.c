/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:23:37 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:23:37 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief The function to find each digit.
/// @param number The string/number without digits to fill.
/// @param n The number to convert.
/// @param divider The divisor of the maximum size that fits in an integer.
/// @param i The current index to fill "number".
/// @return The string/number with the digits filled.
static char	*ft_numbers(char *number, int n, int divider, int i)
{
	int	found_digit;
	int	aux;

	found_digit = 0;
	while (divider > 0)
	{
		aux = n / divider;
		if (aux != 0)
			found_digit = 1;
		if (found_digit)
		{
			if (aux < 0)
				number[i] = 48 + (-aux);
			else
				number[i] = 48 + aux;
			n = n % divider;
			i ++;
		}
		divider = divider / 10;
	}
	number[i] = '\0';
	return (number);
}

/// @brief This function finds the size that the malloc will need.
/// @param n The number that needs to be converted.
/// @return The size that will need the malloc.
static int	found_size(int n)
{
	int	aux;
	int	size;
	int	divider;

	divider = 1000000000;
	size = 12;
	aux = n;
	if (aux == 0)
		return (2);
	if (aux < 0)
		aux = -aux;
	else
		size --;
	while (divider > 0)
	{
		if (aux / divider != 0)
			break ;
		else
			size --;
		divider /= 10;
	}
	return (size);
}

/// @brief This function converts an integer to a char/string type.
/// @param n The integer number to convert.
/// @return The string number to return.
char	*ft_itoa(int n)
{
	char	*number;
	int		i;

	number = malloc(found_size(n));
	if (number == NULL)
		return (NULL);
	i = 0;
	if (n < 0)
	{
		number[i] = '-';
		i ++;
	}
	if (n == 0)
	{
		number[i] = '0';
		i ++;
	}
	ft_numbers(number, n, 1000000000, i);
	return (number);
}
