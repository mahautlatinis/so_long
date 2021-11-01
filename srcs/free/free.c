/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:31:47 by malatini          #+#    #+#             */
/*   Updated: 2021/06/25 14:56:03 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	free_map2d(t_mem *mem)
{
	int	i;

	if (!mem->map)
		return ;
	i = mem->map->lines;
	if (i < 0)
	{
		ft_putstr_fd("Error.\nIncorrect map.\n", 2);
		return ;
	}
	while (i >= 0)
	{
		if (mem->map2d[i])
		{
			free(mem->map2d[i]);
		}
		i--;
	}
}

void	free_data(t_mem *mem)
{
	if (mem->data)
		free(mem->data);
}

void	free_mem(t_mem *mem)
{
	if (!mem)
		exit (EXIT_FAILURE);
	if (mem->vars)
		free(mem->vars);
	if (mem->data)
		free_data(mem);
	if (mem->map2d)
		free_map2d(mem);
	if (mem->map2d)
		free(mem->map2d);
	if (mem->map)
		free(mem->map);
	if (mem->e)
		free_e_list(mem->e);
	if (mem->c)
		free_c_list(mem->c);
	if (mem->p)
		free(mem->p);
	if (mem->floor)
		free(mem->floor);
	if (mem->bottom)
		free(mem->bottom);
	if (mem)
		free(mem);
	exit (EXIT_SUCCESS);
}

void	free_resolutions(int *res_x, int *res_y)
{
	if (res_x)
		free(res_x);
	if (res_y)
		free(res_y);
}

int	close_clean(t_mem *mem)
{
	if (mem->p->img.img)
		mlx_destroy_image(mem->vars->mlx, mem->p->img.img);
	if (mem->e->img.img)
		mlx_destroy_image(mem->vars->mlx, mem->e->img.img);
	if (mem->c->img.img)
		mlx_destroy_image(mem->vars->mlx, mem->c->img.img);
	if (mem->bottom->img)
		mlx_destroy_image(mem->vars->mlx, mem->bottom->img);
	if (mem->floor->img)
		mlx_destroy_image(mem->vars->mlx, mem->floor->img);
	if (mem->data->img)
		mlx_destroy_image(mem->vars->mlx, mem->data->img);
	if (mem->vars->win)
		mlx_destroy_window(mem->vars->mlx, mem->vars->win);
	if (mem->vars->mlx)
		mlx_destroy_display(mem->vars->mlx);
	if (mem->vars->mlx)
		free(mem->vars->mlx);
	free_mem(mem);
	exit (EXIT_FAILURE);
}
