/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 13:32:51 by malatini          #+#    #+#             */
/*   Updated: 2021/06/28 08:31:35 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	temp;
	long	nb;

	nb = n;
	if (fd < 0)
		return ;
	if (nb < 0)
	{
		nb = -nb;
		write(fd, "-", 1);
	}
	if (nb > 9)
		ft_putnbr_fd(nb / 10, fd);
	temp = nb % 10 + '0';
	write(fd, &temp, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (fd < 0 || !s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	count_correct_lines(t_mem *mem)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (mem->map2d[i])
	{
		if (*(mem->map2d[i]) != '\0')
			count++;
		i++;
	}
	return (count);
}

void	max_x(char *line, int nb, t_mem *mem)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (valid_char_mini_map(line[i]))
			res++;
		i++;
	}
	if (res > mem->map->col_max && mem->map->lines == 1)
		mem->map->col_max = res;
	if (res != mem->map->col_max && nb != mem->map->lines)
	{
		if (nb < mem->map->lines && *line != '\0')
		{
			ft_putstr_fd("Error.\nMap not rectangular.\n", 2);
			free_mem(mem);
		}
	}
}

void	ft_bzero(void *s, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return ;
	while (i < n)
		((char *)s)[i++] = '\0';
}
