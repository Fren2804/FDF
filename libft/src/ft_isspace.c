/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>>  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-14 09:23:01 by franmore          #+#    #+#             */
/*   Updated: 2025-01-14 09:23:01 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"
/// @brief This function checks if it is a space " ", form feed "\f", 
///newline "\\n", carriage return "\r", horizontal tab "\t", 
///or vertical tab "\v".
/// @param c The character to check.
/// @return 1 for True "Yes", 0 for False "No".
int	ft_isspace(char c)
{
	if (c == ' ' || c == '\f' || c == '\n' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}
