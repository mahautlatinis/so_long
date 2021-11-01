/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 13:42:21 by malatini          #+#    #+#             */
/*   Updated: 2021/06/25 15:32:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	check_elements_error(t_mem *mem)
{
	if (mem->c->is_empty == true)
	{
		ft_putstr_fd("Error.\nMissing at least one collectible !\n", 2);
		free_mem(mem);
	}
	if (mem->c->is_empty == true)
	{
		ft_putstr_fd("Error.\nMissing at least one exit !\n", 2);
		free_mem(mem);
	}
}

void	check_elements(t_mem *mem)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_collectibles_list(mem->c);
	init_exits_list(mem->e);
	init_player(mem);
	while (i < mem->map->lines && j < mem->map->col_max && mem->map2d[i][j])
	{
		while (j < mem->map->col_max && mem->map2d[i][j])
		{
			is_collectible_char(mem, mem->map2d, i, j);
			is_exit_char(mem, mem->map2d, i, j);
			is_player_char(mem, mem->map2d, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void	check_res(t_mem *mem, int *res_x, int *res_y)
{
	mlx_get_screen_size(mem->vars->mlx, res_x, res_y);
	if (*res_y < M * mem->map->lines || *res_x < M * mem->map->col_max)
	{
		ft_putstr_fd("Error.\nMap is too big for resolution.\n", 2);
		free_mem(mem);
	}
}
