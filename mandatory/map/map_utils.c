/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 02:21:47 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/04/10 00:59:44 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	append_char_to_map(char **map_str, char c)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = *map_str;
	len = ft_strlen(*map_str);
	*map_str = malloc(len + 2);
	if (!*map_str)
	{
		free(tmp);
		return (0);
	}
	i = 0;
	while (i < len)
	{
		(*map_str)[i] = tmp[i];
		i++;
	}
	(*map_str)[len] = c;
	(*map_str)[len + 1] = '\0';
	free(tmp);
	return (1);
}

int	read_file(int fd, char **map_str)
{
	char	buffer[1];
	int		read_count;

	read_count = 0;
	while (read(fd, buffer, 1) > 0)
	{
		read_count++;
		if (!append_char_to_map(map_str, buffer[0]))
			return (0);
	}
	return (read_count > 0);
}

int	check_empty_lines(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i])
	{
		if (map_str[i] == '\n' && map_str[i + 1] == '\n')
		{
			write(1, "Error\n", 6);
			write(1, "Map contains empty lines\n", 25);
			return (0);
		}
		i++;
	}
	if (map_str[0] == '\n' || map_str[ft_strlen(map_str) - 1] == '\n')
	{
		write(1, "Error\n", 6);
		write(1, "Map contains empty lines\n", 25);
		return (0);
	}
	return (1);
}

int	check_map_structure(char **map)
{
	if (!map)
		return (0);
	if (!check_map_walls(map))
	{
		free_map(map);
		return (0);
	}
	if (!check_map_rectangular(map))
	{
		free_map(map);
		return (0);
	}
	return (1);
}

int	check_map_content(char **map)
{
	if (!check_map_characters(map))
	{
		free_map(map);
		return (0);
	}
	if (!check_map_elements(map))
	{
		free_map(map);
		return (0);
	}
	if (!check_valid_path(map))
	{
		free_map(map);
		return (0);
	}
	return (1);
}
