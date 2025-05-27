/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:25:24 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:25:24 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function extracts the digits of each number and writes them 
///to the file descriptor.
/// @param nb The number to operate with.
/// @param fd The file descriptor where to write.
static void	print_number(int nb, int fd)
{
	int		first_digit_found;
	int		count;
	char	digit;

	count = 1000000000;
	first_digit_found = 0;
	while (count > 0)
	{
		if (first_digit_found == 0)
		{
			digit = 48 + nb / count;
			if (digit != '0')
			{
				first_digit_found = 1;
				write(fd, &digit, 1);
			}
		}
		else
		{
			digit = 48 + (nb / count) % 10;
			write(fd, &digit, 1);
		}
		count /= 10;
	}
}

/// @brief This function writes a number to a file descriptor.
/// @param n The number to write.
/// @param fd The file descriptor where to write.
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
			print_number(n, fd);
		}
		else
		{
			if (n == 0)
			{
				write(fd, "0", 1);
			}
			else
			{
				print_number(n, fd);
			}
		}
	}
}
