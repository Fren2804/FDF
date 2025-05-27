/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-03-13 20:48:27 by franmore          #+#    #+#             */
/*   Updated: 2025-03-13 20:48:27 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_sqrt(int nb)
{
	int	aux;
	int	resultado;

	aux = 1;
	resultado = 1;
	if (nb < 0)
		return (0);
	if (nb < 4)
		return (1);
	while (nb >= resultado)
	{
		resultado = aux * aux;
		if (resultado == nb)
			return (aux);
		aux ++;
	}
	return (aux - 2);
}
