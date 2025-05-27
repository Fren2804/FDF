/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:25:12 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:25:12 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function writes the desired character to the desired 
///file descriptor.
/// @param c The character to write.
/// @param fd The file descriptor where to write.
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
