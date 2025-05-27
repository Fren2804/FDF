/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:12:23 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:12:23 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
/// @brief This function allocates space for an array of "num" elements of a 
///given "size" and initializes each bit to 0.
/// @param num The number of elements.
/// @param size The size of each element.
/// @return Returns the matrix filled with 0.
void	*ft_calloc(size_t num, size_t size)
{
	void	*matrix;

	if (num == 0 || size == 0)
		return (ft_calloc(1, 1));
	if ((~(unsigned long)0 / num) < size)
		return (NULL);
	matrix = malloc(num * size);
	if (matrix == NULL)
		return (NULL);
	ft_bzero(matrix, num * size);
	return (matrix);
}
