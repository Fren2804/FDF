/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: franmore <franmore@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-24 21:25:30 by franmore          #+#    #+#             */
/*   Updated: 2025-01-24 21:25:30 by franmore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

/// @brief This function reads the buffer, splits it, joins it, and returns it.
/// @param buff Auxiliary parameter responsible for storing what is read 
///by the read function.
/// @param fd The file descriptor.
/// @param final_buff Parameter that stores the line to return.
/// @param g_rb Parameter where the remaining buffer will be stored.
/// @return Returns the line.
char	*ft_final_buff(char *buff, int fd, char *final_buff, char **g_rb)
{
	int		i;
	int		b_read;
	char	*temp;

	b_read = read(fd, buff, BUFFER_SIZE);
	while (b_read > 0)
	{
		i = 0;
		buff[b_read] = '\0';
		while (buff[i] != '\0' && buff[i] != '\n')
			i++;
		if (buff[i] == '\n')
		{
			temp = ft_substr_gnl(buff, 0, i + 1);
			final_buff = ft_free(final_buff, ft_strjoin(final_buff, temp));
			*g_rb = ft_free(*g_rb, ft_substr_gnl(buff, i + 1, i - b_read - 1));
			free(temp);
			break ;
		}
		final_buff = ft_free(final_buff, ft_strjoin(final_buff, buff));
		b_read = read(fd, buff, BUFFER_SIZE);
	}
	if (b_read < 0 || (b_read == 0 && final_buff[0] == '\0'))
		return (NULL);
	return (final_buff);
}

/// @brief This function reads the file descriptor and returns the line.
/// @param g_re_buff Parameter where the remaining buffer will be stored.
/// @param final_buff Parameter that stores the line to return.
/// @param fd The file descriptor.
/// @return Returns the line.
char	*ft_no_rest_read(char **g_re_buff, char *final_buff, int fd)
{
	char	*buff;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	final_buff = ft_final_buff(buff, fd, final_buff, g_re_buff);
	free(buff);
	if (!final_buff)
		return (NULL);
	return (final_buff);
}

/// @brief Function responsible for handling the remaining buffer.
/// @param g_rb Parameter where the remaining buffer is stored.
/// @param final_buff Parameter that stores the line to return.
/// @param fd The file descriptor.
/// @return Returns the line.
int	ft_rest_read(char **g_rb, char **final_buff)
{
	int	i;
	int	control;
	int	len;

	i = 0;
	control = 0;
	while ((*g_rb)[i] != '\0')
	{
		if ((*g_rb)[i] == '\n')
		{
			control = 1;
			*final_buff = ft_free(*final_buff, ft_substr_gnl(*g_rb, 0, i + 1));
			len = ft_strlen(*g_rb);
			*g_rb = ft_free(*g_rb, ft_substr_gnl(*g_rb, i + 1, len - (i + 1)));
			break ;
		}
		i++;
	}
	if (control == 0)
	{
		*final_buff = ft_free(*final_buff, ft_strjoin(*final_buff, (*g_rb)));
		(*g_rb)[0] = '\0';
	}
	return (control);
}

/// @brief This function checks various variables, frees them, 
///and returns the read line.
/// @param temp Temporal parameter that holds the line to return.
/// @param final_buff Memory address pointing to the line.
/// @param g_rb Static parameter where the remaining buffer is stored.
/// @return Return the line.
char	*final_check(char *temp, char **final_buff, char **g_rb)
{
	if (!temp)
	{
		free(*final_buff);
		free(*g_rb);
		*final_buff = NULL;
		*g_rb = NULL;
		return (NULL);
	}
	*final_buff = temp;
	if ((*g_rb)[0] == '\0')
	{
		free(*g_rb);
		*g_rb = NULL;
	}
	return (*final_buff);
}

/// @brief This function reads and returns up to the next 
///line from the file descriptor.
/// @param fd The file descriptor.
/// @return Returns the read line, or NULL in case of an 
///error or an empty file descriptor.
char	*get_next_line(int fd)
{
	static char	*g_re_buff;
	char		*final_buff;
	char		*temp;
	int			control;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	control = 0;
	final_buff = ft_calloc_gnl(1, sizeof(char));
	if (!final_buff)
		return (NULL);
	if (!g_re_buff)
	{
		g_re_buff = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
		if (!g_re_buff)
			return (NULL);
	}
	if (g_re_buff[0] != '\0')
	{
		control = ft_rest_read(&g_re_buff, &final_buff);
		temp = final_buff;
	}
	if (g_re_buff[0] == '\0' && control == 0)
		temp = ft_no_rest_read(&g_re_buff, final_buff, fd);
	return (final_check(temp, &final_buff, &g_re_buff));
}
