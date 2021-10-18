/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcorneli <marvin@codam.nl>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 20:42:07 by jcorneli          #+#    #+#             */
/*   Updated: 2021/10/17 01:28:38 by jcorneli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <libft.h>
#include <so_long.h>
#include <parser.h>

#include <stdio.h>

int	parse_line(char *line)
{
	static const char	accepted[] = "01CEP";
	int i;

	i = 0;
	while (line[i])
	{
		if (!ft_strchr(accepted, line[i]))
			return (printf("bad_char %d\n", i));

		i++;
	}
	return (0);
}

int	parse_map(char *file, t_scene *scene)
{
	int		fd;
	char	*line;
	int 	len;
	int 	line_counter;

	line_counter = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (printf("map_open_error\n"));
	line = ft_gnl(fd);
	while (line)
	{
		len = ft_strlen(line);
		line_counter++;
		if (parse_line(line) != 0)
		{
			close(fd);
			return (printf("parse_line failed\n"));
		}
		printf("|%s|\n", line);
		line = ft_gnl(fd);
		if (line && ft_strlen(line) != len)
		{
			close(fd);
			return (printf("omdat z'n ene pootje even lang is\n"));
		}
	}
	close(fd);
	return (0);
}