/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uzyberaj <uzyberaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 18:12:58 by uzyberaj          #+#    #+#             */
/*   Updated: 2025/04/09 18:13:25 by uzyberaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	append_char_to_str(char **map_str, char buffer)
{
	char	*tmp;
	int		len;
	int		i;

	tmp = *map_str;
	len = ft_strlen(*map_str);
	*map_str = malloc(len + 2);
	if (!*map_str)
		return (0);
	i = 0;
	while (i < len)
	{
		(*map_str)[i] = tmp[i];
		i++;
	}
	(*map_str)[len] = buffer;
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
		if (!append_char_to_str(map_str, buffer[0]))
			return (0);
	}
	return (read_count > 0);
}
