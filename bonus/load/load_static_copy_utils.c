/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_static_copy_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 15:06:09 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:05:41 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	copy_static_base(char *path, int *i)
{
	char	*base;
	int		j;

	base = "textures/character/animated/static/static_";
	j = 0;
	while (base[j])
	{
		path[*i] = base[j];
		(*i)++;
		j++;
	}
}

void	copy_static_direction(char *path, int *i,
		int dir, const char *directions[])
{
	int	j;

	j = 0;
	while (directions[dir][j])
	{
		path[*i] = directions[dir][j];
		(*i)++;
		j++;
	}
}

void	copy_static_middle(char *path, int *i)
{
	char	*middle;
	int		j;

	middle = "/pepe_static_";
	j = 0;
	while (middle[j])
	{
		path[*i] = middle[j];
		(*i)++;
		j++;
	}
}

void	copy_static_end(char *path, int *i)
{
	char	*end;
	int		j;

	end = ".xpm";
	j = 0;
	while (end[j])
	{
		path[*i] = end[j];
		(*i)++;
		j++;
	}
}
