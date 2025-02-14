/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racamach <racamach@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:36:12 by racamach          #+#    #+#             */
/*   Updated: 2024/07/23 10:15:03 by racamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*buffer;
	t_map	*map;

	if (argc != 2)
	{
		write(2, "Usage: ./bsq <map_file>\n", 24);
		return (1);
	}
	buffer = read_file(argv[1]);
	if (!buffer)
	{
		write(2, "Error reading file\n", 19);
		return (1);
	}
	map = parse_map(buffer);
	if (!map)
	{
		write(2, "Error parsing map\n", 18);
		return (1);
	}
	find_largest_square(map);
	print_map(map);
	free(buffer);
	return (0);
}
