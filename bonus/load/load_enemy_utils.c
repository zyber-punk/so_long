/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_enemy_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyssezyberaj <ulyssezyberaj@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 04:36:55 by ulyssezyber       #+#    #+#             */
/*   Updated: 2025/03/29 17:05:14 by ulyssezyber      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	add_frame_number(char *path, int *i, int frame)
{
	path[*i] = '_';
	(*i)++;
	path[*i] = frame + '0';
	(*i)++;
}

void	copy_base_path(char *path, int *i)
{
	char	*base;
	int		j;

	base = "textures/enemies/animated/";
	j = 0;
	while (base[j])
	{
		path[*i] = base[j];
		(*i)++;
		j++;
	}
}

void	copy_direction(char *path, int *i,
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

void	copy_middle_path(char *path, int *i)
{
	char	*middle;
	int		j;

	middle = "/shiba_";
	j = 0;
	while (middle[j])
	{
		path[*i] = middle[j];
		(*i)++;
		j++;
	}
}

void	copy_end_path(char *path, int *i)
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
