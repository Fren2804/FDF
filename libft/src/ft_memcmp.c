/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:24:39 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:24:39 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief The function compares the bytes of two buffers/strings and returns 
///the difference between them, or stops when the desired limit is reached.
/// @param buf1 The first buffer to compare.
/// @param buf2 The second buffer to compare.
/// @param count The limit of bytes to compare.
/// @return 0 if the limit is reached, or the difference between the byte of 
///buf1 and the byte of buf2.
int	ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	size_t	i;
	char	*aux_buf1;
	char	*aux_buf2;

	aux_buf1 = (char *) buf1;
	aux_buf2 = (char *) buf2;
	i = 0;
	while (i < count)
	{
		if (aux_buf1[i] != aux_buf2[i])
			return ((unsigned char) aux_buf1[i] - (unsigned char) aux_buf2[i]);
		i ++;
	}
	return (0);
}
