/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahautlatinis <mahautlatinis@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:25:54 by malatini          #+#    #+#             */
/*   Updated: 2021/06/24 15:02:37 by malatini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../so_long.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1, t_mem *mem)
{
	int		i;
	char	*cpy;

	i = 0;
	while (s1[i])
		i++;
	cpy = (char *)malloc(sizeof(char) * (i + 1));
	if (!(cpy))
		free_mem(mem);
	i = 0;
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

int	ft_hasnewline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_prep_s(char *s, t_mem *mem)
{
	int		i;
	int		j;
	char	*clean_s;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	clean_s = (char *)malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!(clean_s))
		free_mem(mem);
	i++;
	while (s[i])
		clean_s[j++] = s[i++];
	clean_s[j] = '\0';
	free(s);
	return (clean_s);
}

char	*gnl_strjoin(char *s1, char *s2, t_mem *mem)
{
	char	*single;
	size_t	i;
	size_t	j;
	size_t	l;

	single = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if ((!s1 && !s2) || !(single))
		free_mem(mem);
	i = 0;
	j = 0;
	l = ft_strlen(s1);
	while (i < l)
	{
		single[i] = s1[i];
		i++;
	}
	l = ft_strlen(s2);
	while (j < l)
	{
		single[i + j] = s2[j];
		j++;
	}
	single[i + j] = '\0';
	free(s1);
	return (single);
}
