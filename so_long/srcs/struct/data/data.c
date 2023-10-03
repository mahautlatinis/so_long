/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 18:23:49 by malatini          #+#    #+#             */
/*   Updated: 2021/06/25 17:00:34 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

/* Fichier realise dans le but de me proteger de garbages values */
void	init_data(t_mem *mem)
{
	mem->data->img = NULL;
	mem->data->addr = NULL;
	mem->data->bits_per_pixel = 0;
	mem->data->line_length = 0;
	mem->data->endian = 0;
	mem->data->width = 0;
	mem->data->height = 0;
}

void	init_vars(t_mem *mem)
{
	mem->vars->mlx = NULL;
	mem->vars->win = NULL;
}

void	init_map(t_mem *mem)
{
	mem->map->lines = -1;
	mem->map->col_max = 0;
	mem->map->correct_lines = 0;
}
