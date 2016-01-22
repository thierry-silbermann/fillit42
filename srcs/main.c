/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsilberm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:52:09 by tsilberm          #+#    #+#             */
/*   Updated: 2016/01/21 15:52:48 by tsilberm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

int			main(int argc, char *argv[])
{
	int		fd;
	t_map	map;

	if (argc != 2)
	{
		fillit_error_msg_exit("Usage: ./fillit [map.fillit]");
		return (-1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fillit_error_msg_exit("some open failed somewhere");
	ft_memset(&map, 0, sizeof(map));
	parse(fd, &map);
	close(fd);
	solve(&map);
	return (0);
}
