/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_minimap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 16:25:22 by mahautlat         #+#    #+#             */
/*   Updated: 2021/06/25 16:02:17 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	to_upper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	check_so_long_extension(char *str, char *ext)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (!str[i])
	{
		ft_putstr_fd("Error.\nWrong extension or path specified.\n", 2);
		exit (EXIT_FAILURE);
	}
	while (str[i + j] && ext[j])
	{
		if (to_upper(str[i + j]) == to_upper(ext[j]))
			j++;
		else
			break ;
	}
	if (ext[j] == '\0' && str[i + j] == '\0')
		return (SUCCESS);
	ft_putstr_fd("Error.\nWrong extension or path specified.\n", 2);
	exit (EXIT_FAILURE);
}

int	is_empty_line(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
		return (SUCCESS);
	return (ERROR);
}

int	valid_char_mini_map(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E'
		|| c == 'P' || c == '\n')
		return (SUCCESS);
	return (ERROR);
}

int	mini_map_all_chars(int fd, char *buffer, t_mem *mem)
{
	int	ret;
	int	is_valid;

	ret = 1;
	is_valid = 1;
	while (ret != 0)
	{
		ret = read(fd, buffer, 1);
		is_valid = valid_char_mini_map(buffer[0]);
		if (ret == -1 || is_valid == 0)
		{
			free(buffer);
			ft_putstr_fd("Error.\nIncorrect map !\n", 2);
			free_mem(mem);
		}
		else if (ret == 0)
			return (SUCCESS);
	}
	return (DONE);
}
