/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-25 16:34:18 by franmore          #+#    #+#             */
/*   Updated: 2025-01-25 16:34:18 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function allocates space for an array of "num" elements of a 
///given "size" and initializes each bit to 0.
/// @param num The number of elements.
/// @param size The size of each element.
/// @return Returns the matrix filled with 0.
void	*ft_calloc_gnl(size_t num, size_t size)
{
	void	*matrix;
	size_t	i;
	char	*aux;

	if (num == 0 || size == 0)
		return (malloc(1));
	matrix = malloc(num * size);
	if (matrix == NULL)
		return (NULL);
	aux = (char *) matrix;
	i = 0;
	while (i < (num * size))
	{
		aux[i] = '\0';
		i ++;
	}
	return (matrix);
}

/// @brief This function trims a string by selecting the starting index and 
///the length.
/// @param str The string to trim.
/// @param start The starting index.
/// @param len The length of the string.
/// @return Returns the new trimmed string.
char	*ft_substr_gnl(char const *str, unsigned int start, size_t len)
{
	char	*str2;
	size_t	len_str;
	int		i;

	if (!str)
		return (NULL);
	len_str = ft_strlen(str);
	if (start >= len_str)
		return ((char *) ft_calloc_gnl(1, 1));
	if (len > len_str - start)
		len = len_str - start;
	str2 = malloc(sizeof(char) * (len + 1));
	if (str2 == NULL)
		return (NULL);
	i = 0;
	while ((size_t) i < len && str[i + start] != '\0')
	{
		str2[i] = str[start + i];
		i ++;
	}
	str2[i] = '\0';
	return (str2);
}

/// @brief This function frees the memory of the first parameter and assigns 
///the new value.
/// @param final The parameter to free the memory and assign the new value.
/// @param temp The parameter to assign.
/// @return Returns the desired value and its memory.
char	*ft_free(char *final, char *temp)
{
	free(final);
	final = temp;
	return (final);
}
