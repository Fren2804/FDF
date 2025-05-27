/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:25:49 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:25:49 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function counts the words in the string, delimited by the 
///character.
/// @param str The string to analyze and split.
/// @param c The delimiter to search for.
/// @return Returns the word count.
static int	ft_words_counted(char const *str, char c)
{
	int		i;
	int		words_counted;

	words_counted = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == '\0' || str[i + 1] == c))
			words_counted ++;
		i ++;
	}
	return (words_counted);
}

/// @brief This function fills the matrix by splitting the 
///words and storing them in the matrix.
/// @param matrix The matrix where the words will be stored.
/// @param str The string from which to extract the words.
/// @param c The delimiter to search for.
/// @return Returns the array with each of the separated words.
static char	**ft_fill_matrix(char **matrix, char const *str, char c)
{
	int		i;
	int		j;
	int		words_counted;
	char	*word;

	i = 0;
	j = 0;
	words_counted = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && (str[i + 1] == '\0' || str[i + 1] == c))
		{
			word = ft_substr(str, j, i - j + 1);
			if (!word)
				return (NULL);
			matrix[words_counted] = word;
			words_counted ++;
		}
		if (str[i] == c && (str[i + 1] != '\0' && str[i + 1] != c))
			j = i + 1;
		i ++;
	}
	return (matrix);
}

/// @brief This function frees the memory of the matrix.
/// @param matrix The matrix that needs to be freed.
static void	ft_free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free (matrix[i]);
		i ++;
	}
	free (matrix);
}

/// @brief This function creates a matrix of all words delimited by a 
///desired character.
/// @param str The string to analyze and split.
/// @param c The delimiter to search for.
/// @return Returns the matrix with all the words.
char	**ft_split(char const *str, char c)
{
	char	**matrix;
	int		words_counted;

	if (!str)
		return (NULL);
	words_counted = ft_words_counted(str, c);
	matrix = malloc(sizeof(char *) * (words_counted + 1));
	if (!matrix)
		return (NULL);
	matrix[words_counted] = NULL;
	if (ft_fill_matrix(matrix, str, c) == NULL)
		ft_free_matrix(matrix);
	return (matrix);
}
