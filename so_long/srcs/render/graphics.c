/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 16:44:11 by mahautlat         #+#    #+#             */
/*   Updated: 2023/10/03 22:42:38 by mahautlatin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	draw_player(t_mem *mem)
{
	mem->p->smooth_x += (mem->p->x - mem->p->smooth_x) * 0.5;
	mem->p->smooth_y += (mem->p->y - mem->p->smooth_y) * 0.5;
	draw_on_img(mem->data, &(mem->p->img), (int)(mem->p->smooth_y * M),
		(int)(mem->p->smooth_x * M));
}

void	draw_on_img(t_data *img, t_data *s_img, int startX, int startY)
{
	t_draw	draw;

	draw.x = 0;
	while (draw.x < M)
	{
		draw.y = 0;
		while (draw.y < M)
		{
			draw.r_x = (float)draw.x / (float)M;
			draw.r_y = (float)draw.y / (float)M;
			draw.pos_x = draw.r_x * s_img->width;
			draw.pos_y = draw.r_y * s_img->height;
			draw.color = get_pixel(s_img, draw.pos_x, draw.pos_y);
			draw.p_data_x = startX + draw.x;
			draw.p_data_y = startY + draw.y;
			if (draw.color != (int)BLACK)
				set_pixel(img, draw.p_data_x, draw.p_data_y, draw.color);
			draw.y++;
		}
		draw.x++;
	}
}

int	render_next_frame(t_mem *mem)
{
	mlx_put_image_to_window(mem->vars->mlx, mem->vars->win,
		mem->data->img, 0, 0);
	draw_map(mem);
	draw_elements(mem);
	draw_player(mem);
	mem->frame++;
	return (SUCCESS);
}

int	g_init(t_mem *m)
{
	m->vars->mlx = mlx_init();
	m->frame = 0;
	m->vars->win = mlx_new_window(m->vars->mlx, m->map->col_max * 64,
			m->map->correct_lines * 64, "So long");
	m->data->img = mlx_new_image(m->vars->mlx,
			m->map->col_max * 64, m->map->correct_lines * 64);
	m->data->addr = mlx_get_data_addr(m->data->img,
			&m->data->bits_per_pixel, &m->data->line_length, &m->data->endian);
	init_player_images(m);
	init_floor_images(m);
	init_exits_images(m);
	init_collectibles_images(m);
	init_bottom_images(m);
	so_long_loop(m);
	return (SUCCESS);
}

void	so_long_loop(t_mem *mem)
{
	mlx_loop_hook(mem->vars->mlx, render_next_frame, mem);
	mlx_hook(mem->vars->win, 2, 1L << 0, key_hook, mem);
	mlx_hook(mem->vars->win, 17, 0L, close_clean, mem);
	mlx_loop(mem->vars->mlx);
}
