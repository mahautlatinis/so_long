/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem0.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:08:49 by malatini          #+#    #+#             */
/*   Updated: 2021/06/24 15:48:23 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

t_mem	*initialize_mem(void)
{
	t_mem	*mem;

	mem = (t_mem *)malloc(sizeof(t_mem));
	mem->p = (t_player *)malloc(sizeof(t_player));
	init_player(mem);
	mem->c = (t_collectible_list *)malloc(sizeof(t_collectible_list));
	init_collectibles_list(mem->c);
	mem->e = (t_exit_list *)malloc(sizeof(t_exit_list));
	init_exits_list(mem->e);
	mem->map = (t_map *)malloc(sizeof(t_map));
	init_map(mem);
	mem->map2d = NULL;
	mem->data = (t_data *)malloc(sizeof(t_data));
	init_data(mem);
	mem->vars = (t_vars *)malloc(sizeof(t_vars));
	init_vars(mem);
	mem->floor = NULL;
	mem->bottom = NULL;
	mem->moves = 0;
	mem->frame = 0;
	if (!mem || !mem->p || !mem->c || !mem->e || !mem->map
		|| ! mem->data || !mem->vars)
		free_mem(mem);
	return (mem);
}

void	init_floor_images(t_mem *m)
{
	m->floor = (t_data *)malloc(sizeof(t_data));
	if (!(m->floor))
	{
		ft_putstr_fd("Error.\nError during memory allocation.\n", 2);
		free_mem(m);
	}
	m->floor->img = mlx_xpm_file_to_image(m->vars->mlx,
			"./srcs/textures/dalle0-64.xpm",
			&(m->floor->width), &(m->floor->height));
	m->floor->addr = mlx_get_data_addr(m->floor->img,
			&(m->floor->bits_per_pixel),
			&(m->floor->line_length), &(m->floor->endian));
}

void	init_bottom_images(t_mem *mem)
{
	mem->bottom = (t_data *)malloc(sizeof(t_data));
	if (!(mem->bottom))
	{
		ft_putstr_fd("Error.\nError during memory allocation.\n", 2);
		free_mem(mem);
	}
	mem->bottom->img = mlx_xpm_file_to_image(mem->vars->mlx,
			"./srcs/textures/bottom-64.xpm",
			&(mem->bottom->width), &(mem->bottom->height));
	mem->bottom->addr = mlx_get_data_addr(mem->bottom->img,
			&(mem->bottom->bits_per_pixel),
			&(mem->bottom->line_length), &(mem->bottom->endian));
}
