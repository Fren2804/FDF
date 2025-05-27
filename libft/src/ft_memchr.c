/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:24:44 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:24:44 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
/// @brief This function searches through the bytes of "buf" until it finds 
///"c" or reaches "count". If it finds a match, it returns "buf", but pointing
/// to the match. For example: ("Hello my name is", "y", 
///"strlen((const char *)buf)") returns "y name".
/// @param buf The buffer where the character (unsigned) needs to be searched.
/// @param c The unsigned character that needs to be searched.
/// @param count The limit of characters to search.
/// @return The buffer pointing to the position of the desired character.
/// Or NULL if it hasn't been found.
void	*ft_memchr(const void *buf, int c, size_t count)
{
	char	*aux_buf;
	size_t	i;

	aux_buf = (char *) buf;
	i = 0;
	while (i < count)
	{
		if ((unsigned char) *aux_buf == (unsigned char) c)
			return (aux_buf);
		i ++;
		aux_buf ++;
	}
	return (NULL);
}
