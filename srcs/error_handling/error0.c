/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 15:46:34 by malatini          #+#    #+#             */
/*   Updated: 2021/06/24 21:42:31 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	handle_args_error(int fd, t_mem *mem)
{
	if (fd == -1)
	{
		ft_putstr_fd("Error.\nIncorrect map file specified.\n", 2);
		free_mem(mem);
	}
}

void	handle_fd_errors(int fd, t_mem *mem)
{
	if (fd < 0)
	{
		ft_putstr_fd("Error.\nCould not open the file.\n", 2);
		free_mem(mem);
	}
	if (mem->map->lines == 0 || mem->map->col_max == 0)
	{
		ft_putstr_fd("Error.\nInvalid map.", 2);
		free_mem(mem);
	}
}

void	error_gnl(int fd, char **line, t_mem *mem)
{
	if (fd < 0 || !line)
	{
		ft_putstr_fd("Error.\nSomething went wrong while gnl.\n", 2);
		free_mem(mem);
	}
}

void	error_read(t_mem *mem, char *buffer, int b_read)
{
	if (b_read < 0)
	{
		ft_putstr_fd("Error.\nError during reading.\n", 2);
		free(buffer);
		free_mem(mem);
	}
}

void	handle_bad_char(t_mem *mem, char *line)
{
	if (check_mini_map_chars(line, mem) == ERROR)
	{
		ft_putstr_fd("Error.\nBad character is map.\n", 2);
		free_mem(mem);
	}
}
