/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 11:59:18 by malatini          #+#    #+#             */
/*   Updated: 2021/06/25 15:46:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	handle_error_gnl2(char *line, t_mem *mem, int *i)
{
	if (line[0] != '1' && *i > mem->map->lines)
	{
		ft_putstr_fd("Error.\nInvalid map.\n", 2);
		free_mem(mem);
	}
	check_line(line, mem, i);
}

void	main_errors(t_mem *mem)
{
	if (!mem->c->first || !mem->e->first)
	{
		ft_putstr_fd("Error.\nMissing collectible or exit.\n", 2);
		free_mem(mem);
	}
	if (mem->p->is_found == false)
	{
		ft_putstr_fd("Error.\nMissing player.\n", 2);
		free_mem(mem);
	}
}
